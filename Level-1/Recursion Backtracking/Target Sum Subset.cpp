#include<bits/stdc++.h>
using namespace std;
void print_target_sum(vector<int> vec, int actual_sum, int target, string ans)
{
    if(vec.size() == 0)
    {
        if(target == actual_sum)
            cout<<ans<<endl;
        return;
    }
    int first_num = vec[0];
    vec.erase(vec.begin());
    print_target_sum(vec, actual_sum+first_num, target, ans+to_string(first_num)+" ");
    print_target_sum(vec, actual_sum, target, ans);
}
int main()
{
    vector<int> vec = {10,20,30,40,50};
    int target = 60;
    print_target_sum(vec, 0, target, "");
}