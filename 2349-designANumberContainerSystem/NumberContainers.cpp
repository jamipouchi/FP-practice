#include <set>
#include <unordered_map>

class NumberContainers {
private:
  std::unordered_map<int, int> forward;
  std::unordered_map<int, std::set<int> > backward;

public:
  NumberContainers()
      : forward(std::unordered_map<int, int>()),
        backward(std::unordered_map<int, std::set<int> >()) {}

  void change(int index, int number) {
    if (forward.find(index) != forward.end()) {
      std::set<int>::iterator it =
          backward[forward[index]].find(index);
      backward[forward[index]].erase(it);
      if (backward[forward[index]].empty()) {
        backward.erase(forward[index]);
      }
    }
    forward[index] = number;
    if (backward.find(number) == backward.end()) {
      backward[number] = std::set<int>();
    }
    backward[number].insert(index);
  }

  int find(int number) {
    return backward.find(number) == backward.end() ? -1 : *backward[number].begin();
  }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
