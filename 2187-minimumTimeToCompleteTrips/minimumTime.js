function minimumTime(time, totalTrips) {
    var min = time.reduce(function (min, t) {
        return Math.min(min, t);
    }, Number.MAX_VALUE);
    console.log(min, min * totalTrips);
    var check = function (checkTime) { return time
        .map(function (t) { return Math.floor(checkTime / t); })
        .reduce(function (acc, curr) { return acc + curr; }) >= totalTrips ? Ordering.Big : Ordering.Small; };
    var binSearch = function (left, right) {
        if (left >= right) {
            return left;
        }
        else {
            var mid = Math.floor((left + right) / 2);
            switch (check(mid)) {
                case Ordering.Small:
                    console.log("small", mid);
                    return binSearch(mid + 1, right);
                case Ordering.Big:
                    console.log("big", mid);
                    return binSearch(left, mid);
            }
        }
    };
    return binSearch(min, min * totalTrips);
}
;
var Ordering;
(function (Ordering) {
    Ordering[Ordering["Small"] = 0] = "Small";
    Ordering[Ordering["Big"] = 1] = "Big";
})(Ordering || (Ordering = {}));
// to check time t what we have to do is:
// check (sum (time/t) >= totalTrips) =/> sume(time) /t >= totalTrips (because of integer division...)
// sooo we are  left with a binary search.
console.log(minimumTime([5, 10, 10], 9));
console.log(minimumTime([2], 1));
