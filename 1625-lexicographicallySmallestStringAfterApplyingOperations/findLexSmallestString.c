#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * I didn't find this intuitive, but generating all possible rotations and
 * additions is enough, as there are not so many combinations due to cyclic
 * nature of the string and the operations.
 */

// This can be improved by going on a more bottom-up approach, on each possible
// rotation, check each possible addition -> no longer for a set of seen

struct TrieNode {
  struct TrieNode *children[10];
};

typedef struct TrieNode Trie[10];

char trie_has(const Trie *trie, const char *str) {
  printf("trie_has(%s)\n", str);
  const struct TrieNode *node = trie[str[0] - '0'];
  printf("node=%p\n", node);
  for (int i = 1; str[i]; i++) {
    int idx = str[i] - '0';
    if (!node->children[idx]) {
      return 0;
    }
    node = node->children[idx];
  }
  return 1;
}

char trie_add(Trie *trie, const char *str) {
  struct TrieNode *node = trie[str[0] - '0'];
  for (int i = 1; str[i]; i++) {
    int idx = str[i] - '0';
    if (!node->children[idx]) {
      node->children[idx] = calloc(1, sizeof(struct TrieNode));
    }
    node = node->children[idx];
  }
  return 1;
}

Trie *trie_init() {
  Trie *trie = calloc(1, sizeof(Trie));
  return trie;
}

Trie *trie;
char *minS;

void rotate(char *s, int len, int b) {
  char temp[len + 1];
  strcpy(temp, s);
  for (int i = 0; i < len; i++) {
    s[(i + b) % len] = temp[i];
  }
}

void add(char *s, int len, int a) {
  for (int i = 1; i < len; i += 2) {
    s[i] = (s[i] - '0' + a) % 10 + '0';
  }
}

void dfs(char *s, int len, int a, int b) {
  if (trie_has(trie, s)) {
    return;
  }
  if (strcmp(s, minS) < 0) {
    strcpy(minS, s);
  }
  char s_copy[len + 1];
  strcpy(s_copy, s);
  trie_add(trie, s_copy);
  rotate(s, len, b);
  dfs(s, len, a, b);
  add(s, len, a);
  dfs(s, len, a, b);
}

char *findLexSmallestString(char *s, int a, int b) {
  int len = strlen(s);
  trie = trie_init();
  minS = s;
  dfs(s, len, a, b);
  return minS;
}
