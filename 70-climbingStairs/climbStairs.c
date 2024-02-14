int climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    int pre = 1;
    int curr = 2;
    int tmp;
    while (n-- > 2) {
        tmp = curr;
        curr += pre;
        pre = tmp;
    }
    return curr;
    // s[1] = 1
    // s[2] = 2

    // s[3] = s[1] + s[2] // 1 1 1 ; 2 1 ; 1 2 -> should be 3, which is
    // s[i] = s[i-1]+s[i-2] forall i > 2
}
/*
    You are climbing a staircase. It takes n steps to reach the top.

    Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/