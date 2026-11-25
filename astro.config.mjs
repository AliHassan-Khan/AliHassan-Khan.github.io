// @ts-check
import { defineConfig } from "astro/config";
import tailwindcss from "@tailwindcss/vite";

// https://astro.build/config
export default defineConfig({
  // Added for GitHub Pages (user site: AliHassan-Khan.github.io, so no `base` needed)
  site: "https://alihassan-khan.github.io",
  vite: {
    plugins: [tailwindcss()],
  },
});
