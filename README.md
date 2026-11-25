# Muhammad Ali Hassan | Portfolio

Personal portfolio of Muhammad Ali Hassan, BE Information Security student (3rd semester), published with GitHub Pages at https://alihassan-khan.github.io

## Template credit and license

This website is built on the **[devportfolio](https://github.com/RyanFitzgerald/devportfolio)** template, created by **Ryan Fitzgerald** and released under the **MIT License**.

- Original template: https://github.com/RyanFitzgerald/devportfolio
- Original license: [`LICENSE.md`](LICENSE.md) (MIT, Copyright (c) 2025 Ryan Fitzgerald), kept unchanged in this repository
- Template author's copyright notice and the MIT permission notice must stay with all copies of the template code, so please do not remove `LICENSE.md`
- A credit line with a link to the original repository is shown in the site footer

### What was customised

The template's structure (Astro + Tailwind CSS components, `src/config.ts`) is kept. Changes made by Ali Hassan Khan:

- Replaced all placeholder content in `src/config.ts` with my own bio, skills, education and lab projects
- Added optional config fields (`tagline`, `degree`, `photo`, `currentlyLearning`, `projectsIntro`) and rendered them in the Hero, About and Projects components
- Added a profile photo (`public/photo.jpg`) to the Hero section
- Made social links and the Education `school` field optional so empty items do not render broken links
- Footer: social icons render only when set, plus a copyright line and the template attribution
- Changed the accent colour, reduced the hero heading size for a longer name, added `site` to `astro.config.mjs`, and added a GitHub Actions workflow for Pages deployment

My own content (text, photo and the C++ lab projects in `projects/`) is not part of the template.

## Projects

- `projects/mbr-analyzer` – MBR boot sector analyzer (C++, from Lab 04)
- `projects/disk-layout-planner` – UEFI/GPT disk layout planner (C++, from Lab 03)
- `projects/grade-calculator` – GPA and grade calculator (C++)

## Built with

- [Astro](https://astro.build/) and [Tailwind CSS v4](https://tailwindcss.com/) (via the devportfolio template)
- [IBM Plex Mono](https://fonts.google.com/specimen/IBM+Plex+Mono) from Google Fonts

## Run locally

```
npm install
npm run dev
```

Build for production with `npm run build` (output goes to `dist/`).

## Deploy to GitHub Pages

1. Push this repository to `AliHassan-Khan/AliHassan-Khan.github.io` on the `main` branch
2. In the repository go to **Settings → Pages** and set **Source** to **GitHub Actions**
3. Each push to `main` runs `.github/workflows/deploy.yml`, which builds the site and publishes it

## Editing content

All content lives in `src/config.ts`. Removing `experience` entries (or leaving the array empty) hides that section.

## License

The template code is MIT licensed, Copyright (c) 2025 Ryan Fitzgerald. See [`LICENSE.md`](LICENSE.md).
