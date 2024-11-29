# CS2211 – Lab 11 by Rohin

## 1. Single-line Comments

```
grep -E '^(\s*#|//)' log3.py log3.c | grep -vE '^\s*(#include|#define)'
```

![](2024-11-29-01-22-24.png)

## 2. Imports

```
grep -E '^\s*(import|#include\s*<)' log3.py log3.c
```

![](2024-11-29-01-23-03.png)

## 3. If's

```
grep -E '\bif\b' log3.py log3.c
```

![](2024-11-29-01-23-46.png)

## 4. Assignments, but not Relational

```
grep -E '[^=!<>]=([^=]|$)' log3.py log3.c
```

![](2024-11-29-01-24-03.png)

## 5. Variable Declars

```
grep -E '\b(int|double|long\s+long)\b.*;' log3.c
```

![](2024-11-29-01-24-27.png)
