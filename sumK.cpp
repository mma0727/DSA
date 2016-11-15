#include <vector>
#include <stdexcept>
#include <iostream>
#include <unordered_set>
#include <numeric>

class SumK
{
public:
    
    SumK(int k): _k(k) {}
    /**
    *   \brief Adds/appends list of integers at the end of internal list.
    *
    **/
    const int& getK() const{
        return _k;
    }
    void addLast(const std::vector<int>& list) 
    {
        int n = _nums.size();
        int k = getK();

        _nums.insert(_nums.end(), list.begin(), list.end());
        
        if (_nums.size() < k) return;
        
        else if (_nums.size() == k) {
            _sum.insert(std::accumulate(_nums.begin(), _nums.end(), 0));
        }

        else {
            int start = n > k ? n - k + 1 : 0;
            int sum = 0;
            for (int i = start; i < int(_nums.size()); ++i) {
                sum += _nums[i];
                if (i - start + 1 >= k) {
                    _sum.insert(sum);
                    sum -= _nums[i-k+1];
                }
            }
        }
    }

    /**
    *   \brief Returns boolean representing if any three consecutive integers in the internal list have given sum.
    *
    **/
    bool containsSumK(int sum) 
    {
        return (_sum.find(sum) != _sum.end());
    }
private:
    std::unordered_set<int> _sum;
    std::vector<int> _nums;
    int _k;
};

int main()
{
    SumK s(3);


    std::vector<int> first{1,2,3,4,5,6,7,8,9,10,78,90,0};
    s.addLast(first);

    std::cout << "contains  6: " << s.containsSumK(6) << '\n';
    std::cout << "contains 27: " << s.containsSumK(27) << '\n';
    std::cout << "contains 28: " << s.containsSumK(28) << '\n';
    std::cout << "contains 15: " << s.containsSumK(15) << '\n';

    std::vector<int> second;
    second.push_back(4);
    s.addLast(second);

    std::cout << "contains 168: " << s.containsSumK(168) << '\n';
}

