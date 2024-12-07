# <span style="color:green">Equation de droite</span>
Mardown math notation [1](https://www.upyesp.org/posts/makrdown-vscode-math-notation/) [2](https://le.patak.es/2018/06/25/les-symboles-mathematiques-en-markdown/)

## <span style="color:green">Equation de droite a partir d'un point et d'un vecteur

Un point $ M(x,y) $, apprtient a la droite passant par un point $ P(x_p, y_p) $ ayant un vecteur directeur $ \overrightarrow{v}(x_v, y_v) $ si :

$ \overrightarrow{PM} $ et $ \overrightarrow{v} $ sont colineaire.

$ \overrightarrow{PM}(x - x_p, y - y_p) $

Deux vecteur sont colineaire si le produit en croix des deux vecteur est egal a zeros.

$ (x - x_p) \cdot y_v - (y - y_p) \cdot x_v = 0 $

$ \Leftrightarrow xy_v - x_py_v - yx_v + y_px_v = 0 $

$ \Leftrightarrow y_vx - x_vy + x_vy_p - y_vx_p = 0 $

Equation de la droite passant par un point $ P(x_p, y_p) $ de vecteur directeur $ \overrightarrow{v}(x_v, y_v) $


Si $ x_v $ est nul


$$ x = x_p $$

Si $ y_v $ est nul

$$ y = y_p $$

Sinon

$$ y_vx - x_vy + x_vy_p - y_vx_p = 0 $$


## <span style="color:green">Intersection entre une droite definie par un vecteur et un point et une droite parallele a l'axe x

Soit un point $ P(x_p, y_p) $ et un vecteur directeur $ \overrightarrow{v}(x_v, y_v) $

Equation de la droite parallele a l'axe x:
$$ y = Y $$

## <span style="color:green">Intersection entre une droite definie par un vecteur et un point et une droite parallele a l'axe y

Soit un point $ P(x_p, y_p) $ et un vecteur directeur $ \overrightarrow{v}(x_v, y_v) $

Equation de la droite parallele a l'axe y:
$$ x = X $$

### Le point d'intersection $ I(x_i, y_i) $ a pour coordonnees :

Si $ x_v $ est nul, il n'y a pas de point d'intersection, les droites sont paralleles.

Si $ y_v $ est nul

### $$ x_i = X $$
### $$ y_i = y_p $$

Sinon

### $$ x_i = X $$

### $ y_i = \frac{y_vX +x_vy_p - y_vx_p}{x_v}$
### $ \Leftrightarrow y_i = \frac{y_v(X - x_p)}{x_v} + y_p$
### $$ y_i = y_p + \frac{y_v}{x_v} (X - x_p) $$

## <span style="color:green">A partir de 2 points
Soit deux point :
### $$A(x_a, y_a)$$
### $$B(x_b, y_b)$$

La droite passant par $A$ et $B$ a pour equation :

#### Forme : $ax + by + c = 0$
### $$(y_a - y_b)x + (x_a - x_b)y + x_b \cdot y_a - x_a \cdot y_b = 0$$
#### Forme : $y = ax + b$
### $$ y = \frac{y_b - y_a}{x_b - x_a} \cdot x + y_a - \frac{y_b - y_a}{x_b - x_a} \cdot x_a$$

# <span style="color:green">Intersection de droite</span>
### A partir de deux equation de la forme: $ax + by + c = 0$
Soit deux droite : 
### $$a_1x + b_1y + c_1 = 0$$
### $$a_2x + b_2y + c_2 = 0$$

Le point $p(x, y)$ d'intersection a pour coordonnees
### $$x = \frac {b_1c_2 - b_2c_1}{a_1b_2 - a_2b_1}$$
### $$y = \frac {a_2c_1 - a_1c_2}{a_1b_2 - a_2b_1}$$
Si $a_1b_2 - a_2b_1$ = 0 alors les deux droites sont paralleles, il n'y a pas d'intersection.


### A partir de quatre point distinct
Soit deux point d'une droite
### $$A(x_a, y_a)$$
### $$B(x_b, y_b)$$
Soit deux point d'une autre droite
### $$C(x_c, y_c)$$
### $$D(x_d, y_d)$$

Equation de la premiere droite: $ a_1x + b_1y + c_1 = 0 $

$ a_1 = y_a - y_b $

$ b_1 = x_a - x_b $

$ c_1 = x_b \cdot y_a - x_a \cdot y_b $

Equation de la deuxieme droite: $ a_2x + b_2y + c_2 = 0 $

$ a_2 = y_c - y_d $

$ b_2 = x_c - x_d $

$ c_2 = x_d \cdot y_c - x_c \cdot y_d $

Le point $M(x, y)$ d'intersection a pour coordonnees

### $ a_1x + b_1y + c_1 = 0 \Leftrightarrow x = \frac {b_1}{a_1} \cdot y - \frac {c_1}{a_1} $

### $ a_2x + b_2y + c_2 = 0 \Leftrightarrow - a_2\frac {c_1}{a_1} -a_2\frac {b_1}{a_1}y + b_2y + c_2 = 0 $

### $ \Leftrightarrow (b_2 - a_2\frac {b_1}{a_1})y = a_2\frac {c_1}{a_1} - c_2 $

### $ \Leftrightarrow (a_1b_2 - a_2b_1)y = a_2c_1 - a_1c_2 $


### $$ y =  \frac {a_2c_1 - a_1c_2}{a_1b_2 - a_2b_1} $$

## $ x = \frac {b_1}{a_1} \cdot y - \frac {c_1}{a_1} \Leftrightarrow x = \frac {b_1}{a_1} \cdot \frac {a_2c_1 - a_1c_2}{a_1b_2 - a_2b_1} - \frac {c_1}{a_1} $

## $ \Leftrightarrow x = \frac {b_1(a_2c_1 - a_1c_2)}{a_1(a_1b_2 - a_2b_1)} - \frac {c_1(a_1b_2 - a_2b_1)}{a_1(a_1b_2 - a_2b_1)} $

## $ \Leftrightarrow x = \frac {-a_2b_1c_1 + a_1b_1c_2 - a_1b_2c_1 + a_2b_1c_1}{a_1(a_1b_2 - a_2b_1)}  $

## $ \Leftrightarrow x = \frac {a_1b_1c_2 - a_1b_2c_1}{a_1(a_1b_2 - a_2b_1)}  $

## $$ x = \frac {b_1c_2 - b_2c_1}{a_1b_2 - a_2b_1} $$
