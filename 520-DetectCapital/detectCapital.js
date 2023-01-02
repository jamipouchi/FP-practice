var detectCapitalUse = function (w) {
    return w === w.toUpperCase() ||
        w === w.toLowerCase() ||
        (w.charAt(0) === w.charAt(0).toUpperCase() && w.substring(1) === w.substring(1).toLowerCase());
};
console.log(detectCapitalUse("USA"));
console.log(detectCapitalUse("FlaG"));
