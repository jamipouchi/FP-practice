/**
 * @param {string[]} code
 * @param {string[]} businessLine
 * @param {boolean[]} isActive
 * @return {string[]}
 */
var validateCoupons = function (code, businessLine, isActive) {
  const n = code.length;

  const electronics = [];
  const grocery = [];
  const pharmacy = [];
  const restaurant = [];

  for (let i = 0; i < n; i++) {
    if (!isActive[i]) continue;
    const codeStr = code[i];
    if (!/^[a-zA-Z0-9_]+$/.test(codeStr)) continue;
    const business = businessLine[i];
    if (business === "electronics") electronics.push(codeStr);
    else if (business === "grocery") grocery.push(codeStr);
    else if (business === "pharmacy") pharmacy.push(codeStr);
    else if (business === "restaurant") restaurant.push(codeStr);
  }

  return electronics
    .sort()
    .concat(grocery.sort(), pharmacy.sort(), restaurant.sort());
};
