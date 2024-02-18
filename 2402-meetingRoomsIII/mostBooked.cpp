#include <algorithm>
#include <queue>
#include <vector>

struct Room {
  int index;
  long booked_until;
};

struct compare_room_availability {
  bool operator()(const Room &a, const Room &b) {
    if (a.booked_until == b.booked_until) {
      return a.index > b.index;
    }
    return a.booked_until > b.booked_until;
  }
};

class Solution {
public:
  int mostBooked(int n, std::vector<std::vector<int>> &meetings) {
    std::sort(meetings.begin(), meetings.end(),
              [](const auto &a, const auto &b) { return a[0] < b[0]; });
    std::priority_queue<Room, std::vector<Room>, compare_room_availability>
        room_availability;
    for (int i = 0; i < n; i++) {
      room_availability.push(Room{.index = i, .booked_until = 0});
    }
    std::vector<int> room_usage(n, 0);
    for (auto &meeting : meetings) {
      // 1. Find the available room with lowest index
      std::vector<Room> available_rooms;
      while (room_availability.size() > 0 &&
             room_availability.top().booked_until <= meeting[0]) {
        available_rooms.push_back(room_availability.top());
        room_availability.pop();
      }
      Room next_available_room;
      // 2.a If there is no available room, pick the one which will be available
      // first
      if (available_rooms.empty()) {
        next_available_room = room_availability.top();
        room_availability.pop();
        // 3.a As it's not yet available, the next available time will be adding
        // the meeting duration to when it's free
        room_availability.push(
            Room{.index = next_available_room.index,
                 .booked_until = next_available_room.booked_until + meeting[1] -
                                 meeting[0]});
      } else {
        // 2.b From the available rooms, pick the lowest index
        next_available_room = *std::max_element(
            available_rooms.begin(), available_rooms.end(),
            [](const Room &a, const Room &b) { return a.index > b.index; });
        for (auto room : available_rooms) {
          if (room.index != next_available_room.index) {
            room_availability.push(room);
          } else {
            // 3.b As it's available, set the next available time to when the
            // meeting ends
            room_availability.push(Room{next_available_room.index, meeting[1]});
          }
        }
        available_rooms.clear();
      }
      room_usage[next_available_room.index]++;
    }
    int most_used = 0;
    return std::max_element(room_usage.begin(), room_usage.end()) -
           room_usage.begin();
  }
};
