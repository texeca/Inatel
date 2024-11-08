#include <iostream>
#include <cmath>
#include <list>
#include <algorithm>

using namespace std;

struct ponto {
    int x, y;
};

struct segmento {
    ponto A, B;
};

int sentido(ponto A, ponto B, ponto C) {
    int cross_product = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
    if (cross_product > 0) {
        return 1; // Curva à esquerda
    } else if (cross_product < 0) {
        return -1; // Curva à direita
    } else {
        return 0; // Colinear
    }
}

bool ponto_segmento(segmento S, ponto P) {
    if (sentido(S.A, S.B, P) != 0) {
        return false;
    } else if (P.x > S.A.x && P.x < S.B.x) {
        return true;
    } else if (P.x < S.A.x && P.x > S.B.x) {
        return true;
    } else if (P.y < S.A.y && P.y > S.B.y) {
        return true;
    } else if (P.y > S.A.y && P.y < S.B.y) {
        return true;
    } else {
        return false;
    }
}

bool cmp(ponto a, ponto b) {
    float angA = atan2(a.y, a.x);
    float angB = atan2(b.y, b.x);
    if (angA == angB) {
        float distA = sqrt(pow(a.x, 2) + pow(a.y, 2));
        float distB = sqrt(pow(b.x, 2) + pow(b.y, 2));
        return distA > distB;
    } else {
        return angA < angB;
    }
}

void ordena_pelo_angulo(ponto p[], int n) {
    ponto pivot;
    int pos_pivot;

    pivot = p[0];
    pos_pivot = 0;
    for (int i = 1; i < n; i++) {
        if (p[i].y < pivot.y || (p[i].y == pivot.y && p[i].x < pivot.x)) {
            pivot = p[i];
            pos_pivot = i;
        }
    }

    p[pos_pivot] = p[0];
    p[0] = pivot;

    for (int i = 0; i < n; i++) {
        p[i].x -= pivot.x;
        p[i].y -= pivot.y;
    }

    sort(p + 1, p + n, cmp);

    for (int i = 0; i < n; i++) {
        p[i].x += pivot.x;
        p[i].y += pivot.y;
    }
}

ponto next_to_top(list<ponto>& pilha) {
    ponto top = pilha.back();
    pilha.pop_back();
    ponto next = pilha.back();
    pilha.push_back(top);
    return next;
}

list<ponto> Graham_scan(ponto p[], int n) {
    list<ponto> pilha;
    ordena_pelo_angulo(p, n);

    pilha.push_back(p[0]);
    pilha.push_back(p[1]);
    pilha.push_back(p[2]);

    int i = 3;
    while (i < n) {
        ponto p1 = next_to_top(pilha);
        ponto p2 = pilha.back();
        ponto p3 = p[i];
        
        if (sentido(p1, p2, p3) == 1) {
            pilha.push_back(p3);
            i++;
        } else {
            pilha.pop_back();
        }
    }
    
    return pilha;
}

int main() {
    int n;
    cin >> n;

    ponto P[10];
    for (int i = 0; i < n; i++) {
        cin >> P[i].x >> P[i].y;
    }

    list<ponto> aux = Graham_scan(P, n);
    cout << aux.size() << " lados" << endl;

    return 0;
}
