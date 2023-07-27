import defaultTheme from '@vuepress/theme-default'
import searchPlugin from '@vuepress/plugin-search'

module.exports = {
  title: 'Raytracer Documentation',
  description: 'Documentation for the Raytracer project',
  head: [
    ['link', { rel: 'icon', href: '/logo.png' }],
  ],
  theme : defaultTheme({
    logo: '/logo.png',
    repo: 'https://github.com/EpitechPromo2026/B-OOP-400-MPL-4-1-raytracer-thibault.bernuz',

    navbar: [
      {
        text: 'Guide',
        children: [
          {
            text: 'Introduction',
            link: '/guide/Introduction.md',
          },
          {
            text: 'Personnalisation',
            link: '/guide/How_to_use.md',
          },
        ],
      },
    ],

    sidebar: [
      {
        children: [
          '/guide/Introduction.md',
          '/guide/How_to_use.md', 
        ],
      },
      {
        collapsible: true,
        text: '🎨 Personnalisation & 💼 Partage',
        children: [
          '/guide/Ajouter_nouveau_fichier_de_configuration.md',
          '/guide/Ajouter_nouveau_fichier_de_configuration_externe.md',
        ],
      },
    ],
  }),
  plugins: [
      searchPlugin({
      // options
      }),
  ],
}
