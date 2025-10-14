#!/usr/bin/env node
import fs from 'fs';
import path from 'path';

if (process.argv.length !== 4) {
  console.error('Usage: node generateHtmlHeader.js <input.html> <output.h>');
  process.exit(1);
}

const inputPath = path.resolve(process.argv[2]);
const outputPath = path.resolve(process.argv[3]);

if (!fs.existsSync(inputPath)) {
  console.error(`Input file does not exist: ${inputPath}`);
  process.exit(1);
}

// Read HTML
let html = fs.readFileSync(inputPath, 'utf-8');

// Remove whitespace
html = html
  .replace(/\s+/g, ' ')      // collapse consecutive whitespace
  .replace(/>\s+</g, '><')   // remove space between tags
  .trim();

// Escape backslashes and double quotes
html = html.replace(/\\/g, '\\\\').replace(/"/g, '\\"').replace(/\n/g, "\\n\"\n\"");

// Build header content
const header = `#pragma once
// Auto-generated from ${path.basename(inputPath)}
// Do not edit manually.

constexpr const char INDEX_HTML[] =
"${html}";
`;

fs.mkdirSync(path.dirname(outputPath), { recursive: true });
fs.writeFileSync(outputPath, header);

console.log(`Generated header: ${outputPath}`);
