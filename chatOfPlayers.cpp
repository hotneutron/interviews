#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const char * MATCH_STRING = "chat";

class matcher {
    public:
        matcher() : idx(0) { matchlen = strlen(MATCH_STRING); }
        bool match(char x) {
            if (MATCH_STRING[idx]==x) {
                idx++;
                if (matchlen == idx) {
                    idx = 0;
                }
                return true;
            } else return false;
        }
        char expected() { return MATCH_STRING[idx]; }
    int idx;
    static int matchlen;
};
int matcher::matchlen;

int main()
{
    const char * chatOfPlayers = "chchcathachattat";
    std::vector<matcher *> matchers;
    
    matchers.push_back(new matcher());
    int minMatchers = 1;
    
    for (auto i =0; i<strlen(chatOfPlayers); i++) {
        char y = chatOfPlayers[i];
        bool matched = false;
        //printf("%c", y);
        for (auto j=0; !matched && j < matchers.size() ; j++) {
            //printf("\n[%d]:expect(%c)\n", j, matchers[j]->expected());
            if (matchers[j]->match(y)) {
                matched = true;
                break;
            }
        }
        if (!matched ) { //couldn't find a match
            if (y == MATCH_STRING[0]) {
                matcher* new_matcher = new matcher;
                new_matcher->match(y);
                matchers.push_back(new_matcher);
                minMatchers++;
                //printf("\nnew matcher. Total=%d\n", minMatchers);
            } else {
                printf("\nIllegal Char %c\n", y);
                return -1;
            }
        } else {
        }
    }
    for (auto j=0; j< matchers.size(); j++) {
        char y = matchers[j]->expected();
        if ( y != MATCH_STRING[0]) {
            printf("\nIllegal Char %c\n", y);
            return -1;
        }
    }
    printf("min player %d\n", minMatchers);
    return 0;
}
