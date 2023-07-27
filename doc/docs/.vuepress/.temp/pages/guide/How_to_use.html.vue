<template><div><h1 id="❓-comment-utiliser-le-raytracer" tabindex="-1"><a class="header-anchor" href="#❓-comment-utiliser-le-raytracer" aria-hidden="true">#</a> ❓ Comment utiliser le Raytracer ?</h1>
<h2 id="📦-installation" tabindex="-1"><a class="header-anchor" href="#📦-installation" aria-hidden="true">#</a> 📦 Installation</h2>
<div class="language-bash line-numbers-mode" data-ext="sh"><pre v-pre class="language-bash"><code>$ <span class="token function">git</span> clone git@github.com:EpitechPromo2026/B-OOP-400-MPL-4-1-raytracer-thibault.bernuz.git
$ <span class="token builtin class-name">cd</span> B-OOP-400-MPL-4-1-raytracer-thibault.bernuz
$ <span class="token function">make</span>
</code></pre><div class="line-numbers" aria-hidden="true"><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div></div></div><h2 id="🎲-choix-de-la-configuration" tabindex="-1"><a class="header-anchor" href="#🎲-choix-de-la-configuration" aria-hidden="true">#</a> 🎲 Choix de la configuration</h2>
<p>Pour avoir un rapide aperçu des configurations disponibles, vous pouvez vous rendre dans le dossier <code v-pre>configs/</code></p>
<p>La configuration que vous pouvez utiliser est effectuée est <code v-pre>.cfg</code> dans le fichier <code v-pre>configs/config.cfg</code>.</p>
<h3 id="📝-configuration-pre-installees" tabindex="-1"><a class="header-anchor" href="#📝-configuration-pre-installees" aria-hidden="true">#</a> 📝 Configuration pré-installées</h3>
<p>Par défault dans le dossier <code v-pre>configs/</code> vous avez 2 configurations pré-installées:</p>
<table>
<thead>
<tr>
<th style="text-align:center">Configutation</th>
<th style="text-align:center">Description</th>
<th style="text-align:center">Temps de rendu</th>
</tr>
</thead>
<tbody>
<tr>
<td style="text-align:center"><code v-pre>cornell_box.cfg</code></td>
<td style="text-align:center">Dernière configuration postée, qui donne un rendu assez rapide, sans trop de perfections</td>
<td style="text-align:center">~25m</td>
</tr>
<tr>
<td style="text-align:center"><code v-pre>simple_light.cfg</code></td>
<td style="text-align:center">Similaire à la <code v-pre>config1.cfg</code> mais avec un résultat, plus propre et donc plus de détails</td>
<td style="text-align:center">~7h 30m</td>
</tr>
<tr>
<td style="text-align:center"><code v-pre>two_spheres.xfg</code></td>
<td style="text-align:center">Similaire à la <code v-pre>config1.cfg</code> mais avec tout les effets boosté au maximum, ce qui donne un résultat très long</td>
<td style="text-align:center">~13h 30m</td>
</tr>
</tbody>
</table>
<h3 id="📋-configurations-externes" tabindex="-1"><a class="header-anchor" href="#📋-configurations-externes" aria-hidden="true">#</a> 📋 Configurations externes</h3>
<p>Si vous voulez effectuer vos propres fichiers de configuration en utilisant le format <code v-pre>.cfg</code>, vous pouvez vous référer à la page suivante:</p>
<ul>
<li><RouterLink to="/guide/Ajouter_nouveau_fichier_de_configuration.html">Crée un nouveau fichier de configuration</RouterLink></li>
</ul>
<p>Si vous voulez effectuer vos propres fichiers de configuration en utilisant n'importe quel autre format, vous pouvez vous référer à la page suivante:</p>
<ul>
<li><RouterLink to="/guide/Ajouter_nouveau_fichier_de_configuration_externe.html">Crée un nouveau fichier de configuration externe</RouterLink></li>
</ul>
<p>Si vous avez effectué une configuration qui vous semble intéressante, vous pouvez vous référer à la page suivante:</p>
<ul>
<li><RouterLink to="/guide/Ajouter_nouvelle_configuration.html">Ajouter une configuration</RouterLink></li>
</ul>
<h2 id="🎱-lancer-le-raytracer" tabindex="-1"><a class="header-anchor" href="#🎱-lancer-le-raytracer" aria-hidden="true">#</a> 🎱 Lancer le Raytracer</h2>
<p>Pour jouer, vous devez lancer le programme <code v-pre>raytracer</code> et choisir le fichier de configuration que vous voulez utiliser.</p>
<div class="language-bash line-numbers-mode" data-ext="sh"><pre v-pre class="language-bash"><code>$ ./raytracer configs/<span class="token punctuation">[</span>config_name<span class="token punctuation">]</span> <span class="token operator">></span> image.ppm
</code></pre><div class="line-numbers" aria-hidden="true"><div class="line-number"></div></div></div><div class="custom-container danger"><p class="custom-container-title">🚨 Attention</p>
<p>Il est très important de lancer le programme avec un fichier de configuration, sinon le résultat sera forcément un écran noir.
Le programme ne contient pas de fichier de configuration par défaut.</p>
</div>
</div></template>


