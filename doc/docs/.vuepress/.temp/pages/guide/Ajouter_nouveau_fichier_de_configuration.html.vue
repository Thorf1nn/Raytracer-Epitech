<template><div><h1 id="🖍️-cree-une-nouvelle-configuration" tabindex="-1"><a class="header-anchor" href="#🖍️-cree-une-nouvelle-configuration" aria-hidden="true">#</a> 🖍️ Crée une nouvelle configuration</h1>
<h2 id="📝-pre-requis" tabindex="-1"><a class="header-anchor" href="#📝-pre-requis" aria-hidden="true">#</a> 📝 Pré-requis</h2>
<ul>
<li>
<p>Avoir lu la page <RouterLink to="/guide/Introduction.html">Introduction</RouterLink></p>
</li>
<li>
<p>Avoir lu la page <RouterLink to="/guide/How_to_use.html">Comment utiliser le Raytracer ?</RouterLink></p>
</li>
</ul>
<h2 id="📋-creation" tabindex="-1"><a class="header-anchor" href="#📋-creation" aria-hidden="true">#</a> 📋 Création</h2>
<p>Pour créer un nouveau fichier de configuration, vous devez créer un nouveau fichier dans le dossier <code v-pre>configs/</code> avec l'extension <code v-pre>.cfg</code>. Pour l'illustration de cette page et pour l'exemple, nous allons créer un fichier <code v-pre>test.cfg</code></p>
<div class="language-bash line-numbers-mode" data-ext="sh"><pre v-pre class="language-bash"><code>$ <span class="token function">touch</span> configs/test.cfg
</code></pre><div class="line-numbers" aria-hidden="true"><div class="line-number"></div></div></div><h2 id="⚙️-configuration-du-fichier" tabindex="-1"><a class="header-anchor" href="#⚙️-configuration-du-fichier" aria-hidden="true">#</a> ⚙️ Configuration du fichier</h2>
<p>Comme le veut le format <code v-pre>.cfg</code>, nous allons devoir créer des sections, des clés et des valeurs.</p>
<div class="custom-container tip"><p class="custom-container-title">💡 <ins> Qu'est ce qu'une section ? </ins></p>
<p>Une section est un ensemble de clés et de valeurs. Une section est définie par des deux-points <code v-pre>:</code> ainsi que des crochets <code v-pre>{}</code> et le nom de la section. Par exemple <code v-pre>image:</code> est une section.</p>
<p>Cette section contient des clés et des valeurs. Par exemple <code v-pre>samplesParPixel = 100</code> est une clé et à pour valeur <code v-pre>100</code></p>
</div>
<div class="custom-container danger"><p class="custom-container-title">🚨 <ins> Attention </ins></p>
<p>Les sections sont sensibles aux fautes de frappes et aux conventions.</p>
<blockquote>
<p>Par exemple <code v-pre>image</code> est différent de <code v-pre>Image</code>, ou encore <code v-pre>image</code> est différent de <code v-pre>image:</code></p>
</blockquote>
<p>Il est aussi très important que TOUTES les <em>clés</em> et <em>valeurs</em> doivent être séparées par un <em>=</em> et un <em>espace</em>. Par exemple <code v-pre>samplesPerPixel=100</code> n'est pas valide, il faut <code v-pre>samplesPerPixel=100</code></p>
<p>Il faut également que toutes les <em>clés</em> et <em>valeurs</em> mentionnées dans cette page soit présentent dans votre fichier de configuration. Sinon, votre fichier de configuration ne sera pas valide. Et vous allez alors rencontré des problèmes de rendu lors de l'execution de votre programme.</p>
</div>
<h3 id="🗃️-sections-obligatoires" tabindex="-1"><a class="header-anchor" href="#🗃️-sections-obligatoires" aria-hidden="true">#</a> 🗃️ Sections obligatoires</h3>
<p>Pour que votre fichier de configuration soit valide, vous devez avoir les sections suivantes :</p>
<h5 id="image" tabindex="-1"><a class="header-anchor" href="#image" aria-hidden="true">#</a> <code v-pre>image</code></h5>
<div class="language-ini line-numbers-mode" data-ext="ini"><pre v-pre class="language-ini"><code>image:
{
    <span class="token key attr-name">resolution</span> <span class="token punctuation">=</span> <span class="token value attr-value">{</span>
        <span class="token key attr-name">width</span> <span class="token punctuation">=</span> <span class="token value attr-value">200,</span>
        <span class="token key attr-name">height</span> <span class="token punctuation">=</span> <span class="token value attr-value">200</span>
    }
    <span class="token key attr-name">samplesPerPixel</span> <span class="token punctuation">=</span> <span class="token value attr-value">100,</span>
    <span class="token key attr-name">maxDepth</span> <span class="token punctuation">=</span> <span class="token value attr-value">50</span>
    <span class="token key attr-name">background</span> <span class="token punctuation">=</span> <span class="token value attr-value">{</span>
        <span class="token key attr-name">r</span> <span class="token punctuation">=</span> <span class="token value attr-value">0.7,</span>
        <span class="token key attr-name">g</span> <span class="token punctuation">=</span> <span class="token value attr-value">0.8,</span>
        <span class="token key attr-name">b</span> <span class="token punctuation">=</span> <span class="token value attr-value">1.0</span>
    }
}
</code></pre><div class="line-numbers" aria-hidden="true"><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div></div></div><h5 id="camera" tabindex="-1"><a class="header-anchor" href="#camera" aria-hidden="true">#</a> <code v-pre>camera</code></h5>
<div class="language-ini line-numbers-mode" data-ext="ini"><pre v-pre class="language-ini"><code>camera:
{
    <span class="token key attr-name">lookFrom</span> <span class="token punctuation">=</span> <span class="token value attr-value">{</span>
        <span class="token key attr-name">x</span> <span class="token punctuation">=</span> <span class="token value attr-value">13.0,</span>
        <span class="token key attr-name">y</span> <span class="token punctuation">=</span> <span class="token value attr-value">2.0,</span>
        <span class="token key attr-name">z</span> <span class="token punctuation">=</span> <span class="token value attr-value">3.0</span>
    },
    <span class="token key attr-name">lookAt</span> <span class="token punctuation">=</span> <span class="token value attr-value">{</span>
        <span class="token key attr-name">x</span> <span class="token punctuation">=</span> <span class="token value attr-value">0.0,</span>
        <span class="token key attr-name">y</span> <span class="token punctuation">=</span> <span class="token value attr-value">0.0,</span>
        <span class="token key attr-name">z</span> <span class="token punctuation">=</span> <span class="token value attr-value">0.0</span>
    },
    <span class="token key attr-name">vup</span> <span class="token punctuation">=</span> <span class="token value attr-value">{</span>
        <span class="token key attr-name">x</span> <span class="token punctuation">=</span> <span class="token value attr-value">0.0,</span>
        <span class="token key attr-name">y</span> <span class="token punctuation">=</span> <span class="token value attr-value">1.0,</span>
        <span class="token key attr-name">z</span> <span class="token punctuation">=</span> <span class="token value attr-value">0.0</span>
    },
    <span class="token key attr-name">fov</span> <span class="token punctuation">=</span> <span class="token value attr-value">20.0,</span>
    <span class="token key attr-name">aspectRatio</span> <span class="token punctuation">=</span> <span class="token value attr-value">1.0,</span>
    <span class="token key attr-name">aperture</span> <span class="token punctuation">=</span> <span class="token value attr-value">0.0,</span>
    <span class="token key attr-name">focusDistance</span> <span class="token punctuation">=</span> <span class="token value attr-value">10.0,</span>
    <span class="token key attr-name">time0</span> <span class="token punctuation">=</span> <span class="token value attr-value">0.0,</span>
    <span class="token key attr-name">time1</span> <span class="token punctuation">=</span> <span class="token value attr-value">1.0</span>
}
</code></pre><div class="line-numbers" aria-hidden="true"><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div></div></div><div class="custom-container danger"><p class="custom-container-title">🚨 <ins> Attention </ins></p>
<p>L'ordre des sections n'est pas important. Cependant vous devez absolument avoir les sections <code v-pre>image</code> et <code v-pre>camera</code> dans votre fichier de configuration, elle sont primordiales au bon fonctionnement de votre programme.</p>
</div>
<h3 id="🗂️-sections-optionnelles" tabindex="-1"><a class="header-anchor" href="#🗂️-sections-optionnelles" aria-hidden="true">#</a> 🗂️ Sections optionnelles</h3>
<p>Toutes les sections qui ne sont pas <code v-pre>image</code> et <code v-pre>camera</code> sont optionnelles. Vous pouvez donc les ajouter ou non dans votre fichier de configuration afin de rajouter des particularités à votre rendu final. A présent nous allons travailler dans la section <code v-pre>primitives</code></p>
<h5 id="primitives" tabindex="-1"><a class="header-anchor" href="#primitives" aria-hidden="true">#</a> <code v-pre>primitives</code></h5>
<div class="language-ini line-numbers-mode" data-ext="ini"><pre v-pre class="language-ini"><code>primitives:
{
    <span class="token key attr-name">spheres</span> <span class="token punctuation">=</span> <span class="token value attr-value">(</span>
        {
            <span class="token key attr-name">center</span> <span class="token punctuation">=</span> <span class="token value attr-value">{</span>
                <span class="token key attr-name">x</span> <span class="token punctuation">=</span> <span class="token value attr-value">0.0,</span>
                <span class="token key attr-name">y</span> <span class="token punctuation">=</span> <span class="token value attr-value">-10.0,</span>
                <span class="token key attr-name">z</span> <span class="token punctuation">=</span> <span class="token value attr-value">0.0,</span>
            },
            <span class="token key attr-name">radius</span> <span class="token punctuation">=</span> <span class="token value attr-value">10.0,</span>
            <span class="token key attr-name">material</span> <span class="token punctuation">=</span> <span class="token value attr-value">"<span class="token inner-value">lambertian</span>"</span>
        },
        {
            <span class="token key attr-name">center</span> <span class="token punctuation">=</span> <span class="token value attr-value">{</span>
                <span class="token key attr-name">x</span> <span class="token punctuation">=</span> <span class="token value attr-value">0.0,</span>
                <span class="token key attr-name">y</span> <span class="token punctuation">=</span> <span class="token value attr-value">10.0,</span>
                <span class="token key attr-name">z</span> <span class="token punctuation">=</span> <span class="token value attr-value">0.0</span>
            },
            <span class="token key attr-name">radius</span> <span class="token punctuation">=</span> <span class="token value attr-value">10.0,</span>
            <span class="token key attr-name">material</span> <span class="token punctuation">=</span> <span class="token value attr-value">"<span class="token inner-value">lambertian</span>"</span>
        }
    )
}
</code></pre><div class="line-numbers" aria-hidden="true"><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div></div></div><h5 id="textures" tabindex="-1"><a class="header-anchor" href="#textures" aria-hidden="true">#</a> <code v-pre>textures</code></h5>
<div class="language-ini line-numbers-mode" data-ext="ini"><pre v-pre class="language-ini"><code>textures:
{
    <span class="token key attr-name">checkerTexture</span> <span class="token punctuation">=</span> <span class="token value attr-value">{</span>
        <span class="token key attr-name">colorEven</span> <span class="token punctuation">=</span> <span class="token value attr-value">{</span>
            <span class="token key attr-name">r</span> <span class="token punctuation">=</span> <span class="token value attr-value">0.2,</span>
            <span class="token key attr-name">g</span> <span class="token punctuation">=</span> <span class="token value attr-value">0.3,</span>
            <span class="token key attr-name">b</span> <span class="token punctuation">=</span> <span class="token value attr-value">0.1</span>
        },
        <span class="token key attr-name">colorOdd</span> <span class="token punctuation">=</span> <span class="token value attr-value">{</span>
            <span class="token key attr-name">r</span> <span class="token punctuation">=</span> <span class="token value attr-value">0.9,</span>
            <span class="token key attr-name">g</span> <span class="token punctuation">=</span> <span class="token value attr-value">0.9,</span>
            <span class="token key attr-name">b</span> <span class="token punctuation">=</span> <span class="token value attr-value">0.9</span>
        }
    }
}
</code></pre><div class="line-numbers" aria-hidden="true"><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div><div class="line-number"></div></div></div></div></template>


