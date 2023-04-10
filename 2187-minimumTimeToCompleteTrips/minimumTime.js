"use strict";
var Ordering;
(function (Ordering) {
    Ordering[Ordering["Small"] = 0] = "Small";
    Ordering[Ordering["Big"] = 1] = "Big";
})(Ordering || (Ordering = {}));
function minimumTime(time, totalTrips) {
    const min = time.reduce((min, t) => {
        return Math.min(min, t);
    }, Number.MAX_VALUE);
    const check = (checkTime) => time
        .map((t) => Math.floor(checkTime / t))
        .reduce((acc, curr) => acc + curr) >= totalTrips ? Ordering.Big : Ordering.Small;
    const binSearch = (left, right) => {
        if (left >= right) {
            return left;
        }
        else {
            const mid = Math.floor((left + right) / 2);
            switch (check(mid)) {
                case Ordering.Small:
                    return binSearch(mid + 1, right);
                case Ordering.Big:
                    return binSearch(left, mid);
            }
        }
    };
    return binSearch(min, min * totalTrips);
}
;
// to check time t what we have to do is:
// check (sum (time/t) >= totalTrips) =/> sume(time) /t >= totalTrips (because of integer division...)
// sooo we are  left with a binary search.
console.log(minimumTime([5, 10, 10], 9));
console.log(minimumTime([2], 1));
