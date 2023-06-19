class Solution {
    private int maxAltitude = 0;

    public int largestAltitude(int[] gain) {
        Arrays.stream(gain).reduce(0, (acc, val) -> {
            acc = acc + val;
            if (acc > maxAltitude) {
                maxAltitude = acc;
            }
            return acc;
        });
        return maxAltitude;
    }
}