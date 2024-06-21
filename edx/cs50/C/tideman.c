#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // match the name to the ith candidate
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            // record the rank given for the ith candidate
            ranks[rank] = i;
            return true;
        }
    }
    // no match
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // for each candidate update preferences over those ranked lower
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // iterate though all possible pairings
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            // if i is preffered over j then record winner and loser pairing and increment pair_count
            // if not, we'll come back to j vs i later in the loop and record it then
            // if tied they won't get recorded
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
        }
    }
    return;
}

void merge_sort(pair p[], int s, int e)
{
    // return when size of p is 1
    if (e - s == 0)
    {
        return;
    }

    // find midpoint of the partion from s to e
    int mid = (s + e) / 2;

    // sort left partition, then right partition
    merge_sort(p, s, mid);
    merge_sort(p, mid + 1, e);

    // create a merged array, a copy of current state of p, used for comparison sorting
    pair merged[e - s + 1];
    for (int i = 0; i < e - s + 1; i++)
    {
        merged[i] = p[i];
    }

    int i = s;
    int j = mid + 1;
    // k indexes the sorted result
    int k = 0;

    // e - s + 1 is the size of the resulting sorted array
    while (k < e - s + 1)
    {
        // replace values of p[k] depending on strength of victories
        int i_win = preferences[merged[i].winner][merged[i].loser];
        int j_win = preferences[merged[j].winner][merged[j].loser];

        if (i_win > j_win)
        {
            p[k] = merged[i];
            i++;
            k++;
        }
        else if (i_win < j_win)
        {
            p[k] = merged[j];
            j++;
            k++;
        }
        // in case of tie, just put them both in resulting array and increment k by 2 instead
        else
        {
            p[k] = merged[i];
            p[k + 1] = merged[j];
            i++;
            j++;
            k = k + 2;
        }
        // if incrementing k brings us to the end of the array, we won't want to do more comparions
        // just set p[k] to the appropriate pair

        if (k == e - s)
        {
            if (j > k)
            {
                p[k] = merged[i];
                k++;
            }
            else
            {
                p[k] = merged[j];
                k++;
            }
        }
    }

    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{

    // recursively sort the array of pairs
    merge_sort(pairs, 0, pair_count - 1);

    return;
}


// recursively search for a path from a to b, if exists return true
bool find_path(int a, int b)
{
    // base case, found a direct path from a to b, return true
    if (locked[a][b] == true)
    {
        return true;
    }

    // else call find_path on i to b for any i that a points to
    for (int i = 0; i < candidate_count; i++)
    {
        if (a != i && b != i)
        {
            // if theres a path from a to i then check if there's a path from i to b
            if (locked[a][i] == true)
            {
                // recursively check paths
                if (find_path(i, b))
                {
                    return true;
                }

            }
        }
    }
    // no path found, return false
    return false;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        int win = pairs[i].winner;
        int lose = pairs[i].loser;
        // lock pair

        locked[win][lose] = true;

        // test if created a cycle
        if (find_path(lose, win))
        {
            locked[win][lose] = false;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // if there is no j such that there is a path of j to i, then i is the node of the graph
    for (int i = 0; i < candidate_count; i++)
    {
        // assume no path to i
        bool path = false;
        for (int j = 0; j < candidate_count; j++)
        {
            // if true then j is a path to i
            if (locked[j][i])
            {
                path = true;
            }
        }

        // if path still false then i is the node of the graph
        if (!path)
        {
            printf("%s\n", candidates[i]);
            break;
        }
    }
    return;
}

