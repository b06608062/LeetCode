class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t ret = 0;
    for (int i = 0; i < 32; i++) {
      uint32_t mask = 1 << i;
      mask &= n;
      mask = mask ? 1 : 0;
      ret |= (mask << (31 - i));
    }

    return ret;
  }
};