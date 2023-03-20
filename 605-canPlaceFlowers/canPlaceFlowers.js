var __spreadArray = (this && this.__spreadArray) || function (to, from, pack) {
    if (pack || arguments.length === 2) for (var i = 0, l = from.length, ar; i < l; i++) {
        if (ar || !(i in from)) {
            if (!ar) ar = Array.prototype.slice.call(from, 0, i);
            ar[i] = from[i];
        }
    }
    return to.concat(ar || Array.prototype.slice.call(from));
};
function canPlaceFlowers(flowerbed, n) {
    return __spreadArray(__spreadArray([0], flowerbed, true), [0, 1], false).reduce(function (_a, plot) {
        var num_plots = _a.num_plots, placable_flowers = _a.placable_flowers;
        return plot == 1
            ? { num_plots: 0, placable_flowers: placable_flowers + Math.floor((num_plots - 1) / 2) }
            : { num_plots: num_plots + 1, placable_flowers: placable_flowers };
    }, { num_plots: 0, placable_flowers: 0 }).placable_flowers > n;
}
;
