# 🖍️ Crée une nouvelle configuration

## 📝 Pré-requis

- Avoir lu la page [Introduction](./Introduction.md)

- Avoir lu la page [Comment utiliser le Raytracer ?](./How_to_use.md)

## 📋 Création

Pour créer un nouveau fichier de configuration, vous devez créer un nouveau fichier dans le dossier `configs/` avec l'extension `.cfg`. Pour l'illustration de cette page et pour l'exemple, nous allons créer un fichier `test.cfg`

```bash
$ touch configs/test.cfg
```

## ⚙️ Configuration du fichier

Comme le veut le format `.cfg`, nous allons devoir créer des sections, des clés et des valeurs.

:::tip 💡 <ins> Qu'est ce qu'une section ? </ins>

Une section est un ensemble de clés et de valeurs. Une section est définie par des deux-points `:` ainsi que des crochets `{}` et le nom de la section. Par exemple `image:` est une section.

Cette section contient des clés et des valeurs. Par exemple `samplesParPixel = 100` est une clé et à pour valeur `100`
:::

:::danger 🚨 <ins> Attention </ins>

Les sections sont sensibles aux fautes de frappes et aux conventions.
> Par exemple `image` est différent de `Image`, ou encore `image` est différent de `image:`

Il est aussi très important que TOUTES les *clés* et *valeurs* doivent être séparées par un *=* et un *espace*. Par exemple `samplesPerPixel=100` n'est pas valide, il faut `samplesPerPixel=100`

Il faut également que toutes les *clés* et *valeurs* mentionnées dans cette page soit présentent dans votre fichier de configuration. Sinon, votre fichier de configuration ne sera pas valide. Et vous allez alors rencontré des problèmes de rendu lors de l'execution de votre programme.
:::

### 🗃️ Sections obligatoires

Pour que votre fichier de configuration soit valide, vous devez avoir les sections suivantes :

##### `image`

```ini
image:
{
    resolution = {
        width = 200,
        height = 200
    }
    samplesPerPixel = 100,
    maxDepth = 50
    background = {
        r = 0.7,
        g = 0.8,
        b = 1.0
    }
}
```

##### `camera`

```ini
camera:
{
    lookFrom = {
        x = 13.0,
        y = 2.0,
        z = 3.0
    },
    lookAt = {
        x = 0.0,
        y = 0.0,
        z = 0.0
    },
    vup = {
        x = 0.0,
        y = 1.0,
        z = 0.0
    },
    fov = 20.0,
    aspectRatio = 1.0,
    aperture = 0.0,
    focusDistance = 10.0,
    time0 = 0.0,
    time1 = 1.0
}
```

:::danger 🚨 <ins> Attention </ins>
L'ordre des sections n'est pas important. Cependant vous devez absolument avoir les sections `image` et `camera` dans votre fichier de configuration, elle sont primordiales au bon fonctionnement de votre programme.
:::

### 🗂️ Sections optionnelles

Toutes les sections qui ne sont pas `image` et `camera` sont optionnelles. Vous pouvez donc les ajouter ou non dans votre fichier de configuration afin de rajouter des particularités à votre rendu final. A présent nous allons travailler dans la section `primitives`

##### `primitives`

```ini
primitives:
{
    spheres = (
        {
            center = {
                x = 0.0,
                y = -10.0,
                z = 0.0,
            },
            radius = 10.0,
            material = "lambertian"
        },
        {
            center = {
                x = 0.0,
                y = 10.0,
                z = 0.0
            },
            radius = 10.0,
            material = "lambertian"
        }
    )
}
```

##### `textures`

```ini
textures:
{
    checkerTexture = {
        colorEven = {
            r = 0.2,
            g = 0.3,
            b = 0.1
        },
        colorOdd = {
            r = 0.9,
            g = 0.9,
            b = 0.9
        }
    }
}
```
