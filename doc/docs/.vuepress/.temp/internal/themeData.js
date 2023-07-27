export const themeData = JSON.parse("{\"logo\":\"/logo.png\",\"repo\":\"https://github.com/EpitechPromo2026/B-OOP-400-MPL-4-1-raytracer-thibault.bernuz\",\"navbar\":[{\"text\":\"Guide\",\"children\":[{\"text\":\"Introduction\",\"link\":\"/guide/Introduction.md\"},{\"text\":\"Personnalisation\",\"link\":\"/guide/How_to_use.md\"}]}],\"sidebar\":[{\"children\":[\"/guide/Introduction.md\",\"/guide/How_to_use.md\"]},{\"collapsible\":true,\"text\":\"🎨 Personnalisation & 💼 Partage\",\"children\":[\"/guide/Ajouter_nouveau_fichier_de_configuration.md\",\"/guide/Ajouter_nouveau_fichier_de_configuration_externe.md\"]}],\"locales\":{\"/\":{\"selectLanguageName\":\"English\"}},\"colorMode\":\"auto\",\"colorModeSwitch\":true,\"selectLanguageText\":\"Languages\",\"selectLanguageAriaLabel\":\"Select language\",\"sidebarDepth\":2,\"editLink\":true,\"editLinkText\":\"Edit this page\",\"lastUpdated\":true,\"lastUpdatedText\":\"Last Updated\",\"contributors\":true,\"contributorsText\":\"Contributors\",\"notFound\":[\"There's nothing here.\",\"How did we get here?\",\"That's a Four-Oh-Four.\",\"Looks like we've got some broken links.\"],\"backToHome\":\"Take me home\",\"openInNewWindow\":\"open in new window\",\"toggleColorMode\":\"toggle color mode\",\"toggleSidebar\":\"toggle sidebar\"}")

if (import.meta.webpackHot) {
  import.meta.webpackHot.accept()
  if (__VUE_HMR_RUNTIME__.updateThemeData) {
    __VUE_HMR_RUNTIME__.updateThemeData(themeData)
  }
}

if (import.meta.hot) {
  import.meta.hot.accept(({ themeData }) => {
    __VUE_HMR_RUNTIME__.updateThemeData(themeData)
  })
}
