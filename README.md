# Cube3D
## Author's
Yohann Gaiffier and Stephane Vogrig  

## About
Cub3D is a 42 school project to discover the ray casting technique.
This technique was used for the personal shooter game Wolfstein3d in 1992.
The goal of the project is to build small game engine to render a 2D map in an apparent 3D environment, where the player can move in a first person perspective.

### Documentations and tutorials

[id-softwar - original source of Wolfstein3d - 1992](https://github.com/id-Software/wolf3d) 
#### General
[Ray casting - Wikipedia en](https://en.wikipedia.org/wiki/Ray_casting)  
[Raycasting - Wikipedia fr](https://fr.wikipedia.org/wiki/Raycasting)  
[Les meilleurs cours et tutoriel 2d/3d/jeux - developpez.com](https://jeux.developpez.com/tutoriels/?page=mot)

#### Raycasting article
 [xitog](https://xitog.github.io/dgx/passetemps/tech_raycasting_fr.html)
[Lode's Computer Graphic Tutorial - 2004-2020 - part : 1](https://lodev.org/cgtutor/raycasting.html)
[2](https://lodev.org/cgtutor/raycasting2.html)
[3](https://lodev.org/cgtutor/raycasting3.html)
[4](https://lodev.org/cgtutor/raycasting4.html)  
[S3DE - projet tutore IUT d'Orsay](http://zupi.free.fr/PTuto/index.php?ch=ptuto&p=ray)  
[Le Lancer de rayon Ray casting - Jean-Baptiste Yunes -10/2018](https://yunes.informatique.univ-paris-diderot.fr/wp-content/uploads/cours/INFOGRAPHIE/08-Raycasting.pdf)  
[Ray casting game tutorial - Hot Source](https://hotsource.dev/2019/05/03/raycasting-game-tutorial-part-1-building-the-engine/)  
[A first-person engine in 265 lines by Hunter Loftis](https://www.playfuljs.com/a-first-person-engine-in-265-lines/)  
[Ray-Casting Tutorial - F. Permadi - 1996-2010](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/)  
[Comment DOOM et Wolfstein affichaient leurs graphismes - Guy Grave - 29/07/1996](https://guy-grave.developpez.com/tutoriels/jeux/doom-wolfenstein-raycasting/)  
[RayCastingTutorial - Vinicius Reif Biavatti - 03/10/2019](https://github.com/vinibiavatti1/RayCastingTutorial/wiki)
#### raycasting video

[Super fast raycasting in tiled worlds using DDA](https://www.youtube.com/watch?v=NbSee-XM7WA&t=1236s)  
[Make your own raycaster](https://www.youtube.com/watch?v=gYRrGTC7GtA&t=188s)  
[Decouvrons le raycasting](https://www.youtube.com/watch?v=xZe0ZYPzxkg&t=61s)  
[Ray casting fully explained, Pseudo 3d game](https://www.youtube.com/watch?v=g8p7nAbDz6Y)  
[Wolfstein 3D's map renderer](https://www.youtube.com/watch?v=eOCQfxRQ2pY)  

#### exemple github
[Samu Aaltonen - doom-nukem](https://github.com/MeowBoy326/doom-nukem-raycasting)  
[Samu Aaltonen - wolf3d](https://github.com/samuaaltonen/wolf3d)

#### Correction
[Enzo Degraeve](https://enzodeg40.github.io/42-Evals/Cursus/Cub3d/)  
[42evals](https://www.42evals.com/sheets/66ba244998d302d110c31b6a)

## Utilisation du Tester

Ce script permet de tester l’exécutable _cub3d_ (ou _cub3d_bonus_) avec différents fichiers de cartes et un temps limite défini.

### Utilisation

```bash
./tester.sh <FOLDER_MAPS> <TIME_LIMIT> [bonus]
```

- **FOLDER_MAPS** : chemin du dossier contenant les cartes (.cub)
- **TIME_LIMIT** : temps limite (en secondes) pour chaque carte
- **bonus**       : optionnel, lance `cub3d_bonus` à la place de `cub3d`

Exemple :
```bash
./tester.sh maps 5 bonus
```

### Fonctionnement

1. Le script recherche tous les fichiers présents dans le dossier spécifié par `FOLDER_MAPS`.
2. Il exécute chaque fichier de carte avec `cub3d` ou `cub3d_bonus`.
3. Un timeout (défini par `TIME_LIMIT`) arrête l’exécution si elle dépasse la limite fixée.
4. Le script affiche pour chaque test (numéroté sous la forme 001, 002, 003, ...) le fichier testé ainsi que le résultat (VALID, SEGFAULT, MLX_ERROR, NO_VALID).
5. Les résultats plus détaillés sont inscrits dans le fichier `tester.log`.

### Personnalisation

- Vous pouvez personnaliser le nom de l’exécutable (par défaut `cub3d` ou `cub3d_bonus` s’il reçoit l’argument `bonus`) en modifiant la variable `CUB3D_EXEC`.
- Le fichier de log par défaut est `tester.log`. Vous pouvez le redéfinir dans la variable `LOG_FILE`.

### Pré-requis

- Avoir un exécutable `cub3d` ou `cub3d_bonus` dans le même dossier.
- Disposer du dossier contenant les cartes (.cub).
