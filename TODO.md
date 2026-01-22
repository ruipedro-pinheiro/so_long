# SO_LONG - TODO

## 1. MAP VALIDATION
- [ ] Check extension `.ber`
- [ ] Check caracteres valides (0, 1, C, E, P uniquement)
- [ ] Check exactement 1 `P` (player)
- [ ] Check exactement 1 `E` (exit)
- [ ] Check au moins 1 `C` (collectible)
- [ ] Check map rectangulaire
- [ ] Check bordures (murs partout)
- [ ] **Flood fill** - verifier chemin valide (P -> tous C -> E)
- [ ] Messages d'erreur: "Error\n" + message explicite

## 2. PARSING & DATA
- [x] Parser la map (GNL + split)
- [ ] Stocker position player (x, y)
- [ ] Stocker position exit
- [ ] Compter collectibles
- [ ] Stocker dimensions map (width, height)

## 3. GRAPHICS
- [x] Init MLX + fenetre
- [ ] Taille fenetre = map * tile_size
- [ ] Charger sprites XPM (wall, floor, player, exit, collectible)
- [ ] Render map selon contenu
- [x] ESC ferme proprement
- [x] Click X ferme proprement

## 4. GAMEPLAY
- [ ] Mouvement WASD (ou fleches)
- [ ] Bloquer sur murs (1)
- [ ] Collecter C (disparait)
- [ ] Exit bloque tant que C restants
- [ ] Exit quand tous C + sur E = victoire
- [ ] Compteur mouvements (ft_printf dans shell)

## 5. CLEAN EXIT
- [ ] Free toute la memoire
- [ ] Destroy images MLX
- [ ] Destroy window + display

---

## BONUS (apres mandatory PARFAIT)
- [ ] Ennemis qui patrouillent
- [ ] Animations sprites
- [ ] Compteur a l'ecran (pas shell)

---

## ASSETS (Stardew Valley theme)
- [x] ground.xpm
- [ ] wall.xpm
- [ ] player.xpm
- [ ] exit.xpm
- [ ] collectible.xpm

*Author: rpinheir*
