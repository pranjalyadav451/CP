/*  -*- coding: utf-8 -*-
 *
 * d.cc: D - Bracket Score 2
 */

#include<bits/stdc++.h>

using namespace std;

/* constant */

const int MAX_N = 200000;
const int MAX_N2 = MAX_N * 2;

/* typedef */

typedef stack<int> sti;
typedef pair<int, int> pii;

/* global variables */

int as[MAX_N2];
pii ps[MAX_N2];
bool cs[MAX_N2];
char s[MAX_N2 + 4];

/* subroutines */

/* main */

int main() {
  int n;
  scanf("%d", &n);
  int n2 = n * 2;

  for (int i = 0; i < n2; i++)
    scanf("%d", as + i), ps[i] = pii(as[i], i);
  sort(ps, ps + n2);

  for (int i = 0; i < n; i++) cs[ps[i].second] = true;

  sti q;
  for (int i = 0; i < n2; i++) {
    if (! q.empty() && cs[q.top()] != cs[i]) {
      int j = q.top(); q.pop();
      s[j] = '(', s[i] = ')';
    }
    else
      q.push(i);
  }

  puts(s);
  return 0;
}
