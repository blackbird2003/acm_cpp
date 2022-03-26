//
// Created by vv123 on 2022/3/22.
//
//
// Created by vv123 on 2022/3/20.
//
#include <iostream>
#include <string>

std::string name[5] = {"dragon", "ninja", "iceman", "lion", "wolf"};
int cost[5];
int mincost;
int order[2][5] = {{2, 3, 4, 1, 0},
                   {3, 0, 1, 2, 4}};

class Headquarters {
public:
    static int M;
    int money, type, amount, runout, cnt[5], pointer;
    std::string camp;
    Headquarters(int Type): type(Type), money(M), amount(0), runout(0), pointer(0) {
        camp = type == 0 ? "red" : "blue";
        for (int i = 0; i < 5; i++) cnt[i] = 0;
    }
    void work(int time) {
        printf("%03d %s ", time, camp.c_str());
        if (money < mincost) {
            runout = 1;
            puts("headquarter stops making warriors");
        } else {
            for (int i = pointer; i < 5 + pointer; i++) {
                int t = order[type][i % 5];
                if (cost[t] <= money) {
                    money -= cost[t];
                    amount++;
                    cnt[t]++;
                    pointer = (i + 1) % 5;
                    printf("%s %d born with strength %d,%d %s in %s headquarter\n", name[t].c_str(), amount, cost[t], cnt[t], name[t].c_str(), camp.c_str());
                    break;
                }
            }
        }
    }
};
int Headquarters::M;
int main() {
    int T;
    std::cin >> T;
    for (int k = 1; k <= T; k++) {
        std::cout << "Case:" << k << std::endl;


        std::cin >> Headquarters::M;
        mincost = 10000;
        for (int i = 0; i < 5; i++) {
            std::cin >> cost[i];
            mincost = std::min(mincost, cost[i]);
        }

        Headquarters red(0), blue(1);
        for (int t = 0; !red.runout  || !blue.runout; t++) {
            if (!red.runout) red.work(t);
            if (!blue.runout) blue.work(t);
        }
    }
    return 0;
}
