# ❓ Comment utiliser le Raytracer ?

## 📦 Installation

```bash
$ git clone git@github.com:EpitechPromo2026/B-OOP-400-MPL-4-1-raytracer-thibault.bernuz.git
$ cd B-OOP-400-MPL-4-1-raytracer-thibault.bernuz
$ make
```

## 🎲 Choix de la configuration

Pour avoir un rapide aperçu des configurations disponibles, vous pouvez vous rendre dans le dossier `configs/`

La configuration que vous pouvez utiliser est effectuée est `.cfg` dans le fichier `configs/config.cfg`.


### 📝 Configuration pré-installées

Par défault dans le dossier `configs/` vous avez 2 configurations pré-installées:

Configutation | Description | Temps de rendu |
:---:|:---:|:---:|
`cornell_box.cfg` | Dernière configuration postée, qui donne un rendu assez rapide, sans trop de perfections | ~25m|
`simple_light.cfg` | Similaire à la `config1.cfg` mais avec un résultat, plus propre et donc plus de détails | ~7h 30m |
`two_spheres.xfg` | Similaire à la `config1.cfg` mais avec tout les effets boosté au maximum, ce qui donne un résultat très long | ~13h 30m |

### 📋 Configurations externes

Si vous voulez effectuer vos propres fichiers de configuration en utilisant le format `.cfg`, vous pouvez vous référer à la page suivante:
- [Crée un nouveau fichier de configuration](./Ajouter_nouveau_fichier_de_configuration.md)

Si vous voulez effectuer vos propres fichiers de configuration en utilisant n'importe quel autre format, vous pouvez vous référer à la page suivante:
- [Crée un nouveau fichier de configuration externe](./Ajouter_nouveau_fichier_de_configuration_externe.md)

Si vous avez effectué une configuration qui vous semble intéressante, vous pouvez vous référer à la page suivante:
- [Ajouter une configuration](./Ajouter_nouvelle_configuration.md)

## 🎱 Lancer le Raytracer

Pour jouer, vous devez lancer le programme `raytracer` et choisir le fichier de configuration que vous voulez utiliser.

```bash
$ ./raytracer configs/[config_name] > image.ppm
```

:::danger 🚨 Attention
Il est très important de lancer le programme avec un fichier de configuration, sinon le résultat sera forcément un écran noir.
Le programme ne contient pas de fichier de configuration par défaut.
:::
