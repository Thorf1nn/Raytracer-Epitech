export const searchIndex = [
  {
    "title": "Hello VuePress",
    "headers": [],
    "path": "/",
    "pathLocale": "/",
    "extraFields": []
  },
  {
    "title": "🖍️ Crée une nouvelle configuration",
    "headers": [
      {
        "level": 2,
        "title": "📝 Pré-requis",
        "slug": "📝-pre-requis",
        "link": "#📝-pre-requis",
        "children": []
      },
      {
        "level": 2,
        "title": "📋 Création",
        "slug": "📋-creation",
        "link": "#📋-creation",
        "children": []
      },
      {
        "level": 2,
        "title": "⚙️ Configuration du fichier",
        "slug": "⚙️-configuration-du-fichier",
        "link": "#⚙️-configuration-du-fichier",
        "children": [
          {
            "level": 3,
            "title": "🗃️ Sections obligatoires",
            "slug": "🗃️-sections-obligatoires",
            "link": "#🗃️-sections-obligatoires",
            "children": []
          },
          {
            "level": 3,
            "title": "🗂️ Sections optionnelles",
            "slug": "🗂️-sections-optionnelles",
            "link": "#🗂️-sections-optionnelles",
            "children": []
          }
        ]
      }
    ],
    "path": "/guide/Ajouter_nouveau_fichier_de_configuration.html",
    "pathLocale": "/",
    "extraFields": []
  },
  {
    "title": "✨ Le contenu des fichiers",
    "headers": [
      {
        "level": 2,
        "title": "📝 Pré-requis",
        "slug": "📝-pre-requis",
        "link": "#📝-pre-requis",
        "children": []
      },
      {
        "level": 2,
        "title": "🆕 Le contenu des Interfaces",
        "slug": "🆕-le-contenu-des-interfaces",
        "link": "#🆕-le-contenu-des-interfaces",
        "children": []
      },
      {
        "level": 2,
        "title": "🔧 Les fonctions principal",
        "slug": "🔧-les-fonctions-principal",
        "link": "#🔧-les-fonctions-principal",
        "children": []
      },
      {
        "level": 2,
        "title": "⚙️ Le Fichier de configration",
        "slug": "⚙️-le-fichier-de-configration",
        "link": "#⚙️-le-fichier-de-configration",
        "children": []
      },
      {
        "level": 2,
        "title": "🧭 Le Makefile",
        "slug": "🧭-le-makefile",
        "link": "#🧭-le-makefile",
        "children": []
      }
    ],
    "path": "/guide/Ajouter_nouveau_fichier_de_configuration_externe.html",
    "pathLocale": "/",
    "extraFields": []
  },
  {
    "title": "❓ Comment utiliser le Raytracer ?",
    "headers": [
      {
        "level": 2,
        "title": "📦 Installation",
        "slug": "📦-installation",
        "link": "#📦-installation",
        "children": []
      },
      {
        "level": 2,
        "title": "🎲 Choix de la configuration",
        "slug": "🎲-choix-de-la-configuration",
        "link": "#🎲-choix-de-la-configuration",
        "children": [
          {
            "level": 3,
            "title": "📝 Configuration pré-installées",
            "slug": "📝-configuration-pre-installees",
            "link": "#📝-configuration-pre-installees",
            "children": []
          },
          {
            "level": 3,
            "title": "📋 Configurations externes",
            "slug": "📋-configurations-externes",
            "link": "#📋-configurations-externes",
            "children": []
          }
        ]
      },
      {
        "level": 2,
        "title": "🎱 Lancer le Raytracer",
        "slug": "🎱-lancer-le-raytracer",
        "link": "#🎱-lancer-le-raytracer",
        "children": []
      }
    ],
    "path": "/guide/How_to_use.html",
    "pathLocale": "/",
    "extraFields": []
  },
  {
    "title": "🏁 Introduction",
    "headers": [
      {
        "level": 2,
        "title": "📖 Présentation",
        "slug": "📖-presentation",
        "link": "#📖-presentation",
        "children": [
          {
            "level": 3,
            "title": "🤨 Qu'est-ce qu'un Raytracer ?",
            "slug": "🤨-qu-est-ce-qu-un-raytracer",
            "link": "#🤨-qu-est-ce-qu-un-raytracer",
            "children": []
          }
        ]
      },
      {
        "level": 2,
        "title": "📋 Prérequis",
        "slug": "📋-prerequis",
        "link": "#📋-prerequis",
        "children": []
      }
    ],
    "path": "/guide/Introduction.html",
    "pathLocale": "/",
    "extraFields": []
  },
  {
    "title": "",
    "headers": [],
    "path": "/404.html",
    "pathLocale": "/",
    "extraFields": []
  }
]

if (import.meta.webpackHot) {
  import.meta.webpackHot.accept()
  if (__VUE_HMR_RUNTIME__.updateSearchIndex) {
    __VUE_HMR_RUNTIME__.updateSearchIndex(searchIndex)
  }
}

if (import.meta.hot) {
  import.meta.hot.accept(({ searchIndex }) => {
    __VUE_HMR_RUNTIME__.updateSearchIndex(searchIndex)
  })
}
