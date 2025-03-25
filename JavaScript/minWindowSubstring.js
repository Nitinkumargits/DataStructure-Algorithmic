function minWindow(s, t) {
  if (s.length === 0 || t.length === 0) return "";
  let freqT = new Map(),
    freqS = new Map();
  for (let char of t) freqT.set(char, (freqT.get(char) || 0) + 1);
  let required = freqT.size,
    formed = 0,
    left = 0,
    right = 0;
  let minLen = Infinity,
    start = -1;
  while (right < s.length) {
    let char = s[right];
    freqS.set(char, (freqS.get(char) || 0) + 1);
    if (freqT.has(char) && freqS.get(char) === freqT.get(char)) formed++;
    while (formed === required) {
      if (right - left + 1 < minLen) {
        minLen = right - left + 1;
        start = left;
      }
      let leftChar = s[left];
      freqS.set(leftChar, freqS.get(leftChar) - 1);
      if (freqT.has(leftChar) && freqS.get(leftChar) < freqT.get(leftChar))
        formed--;
      left++;
    }
    right++;
  }
  return start === -1 ? "" : s.substring(start, start + minLen);
}
// Example usage
console.log("Output:", minWindow("ADOBECODEBANC", "ABC"));
