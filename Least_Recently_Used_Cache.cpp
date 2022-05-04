#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define N 100005

void lru_page_replacement(int[], int, int);

int main(void)
{
    int number_of_references;
    int frame_size;
    int pages[N];
    cout << "Number of Frames: ";
    cin >> frame_size;

    cout << "Page Reference Stream Length: ";
    cin >> number_of_references;

    cout << "Page Reference Stream:\n";
    for (int i = 0; i < number_of_references; i++)
        cin >> pages[i];
    lru_page_replacement(pages, number_of_references, frame_size);
    return 0;
}

void lru_page_replacement(int *pages, int number_of_references, int frame_size)
{
    unordered_set<int> s;
    unordered_map<int, int> indexes;

    int page_faults = 0;
    for (int i = 0; i < number_of_references; i++)
    {

        if (s.find(pages[i]) != s.end())
        {
            cout << "Reference to page " << pages[i] << " did not cause a page fault\n";
        }
        else
        {
            if ((int)s.size() < frame_size)
            {
                s.insert(pages[i]);
                page_faults++;
            }
            else
            {
                int lru = INT_MAX, val;
                for (auto it : s)
                {
                    if (indexes[it] < lru)
                    {
                        lru = indexes[it];
                        val = it;
                    }
                }
                s.erase(val);
                s.insert(pages[i]);
                page_faults++;
            }
            cout << "Reference to page " << pages[i] << " caused a page fault\n";
        }
        indexes[pages[i]] = i;
    }
    cout << "\nTotal Page Faults: " << page_faults;
}