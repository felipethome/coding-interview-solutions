const fs = require('fs');
const path = require('path');
const util = require('util');
const HTML = require('./HTML');

const rootDir = '../src/cpp';

const ignoredDirs = new Set([]);

const ignoredFiles = new Set([
  'test.cpp'
]);

const allowedExts = new Set([
  '.c',
  '.cpp',
]);

const buildFile = './build/index.html'

const dirs = fs.readdirSync(rootDir).filter((dir) => {
  const stats = fs.statSync(path.join(rootDir, dir));
  if (!ignoredDirs.has(dir) && stats.isDirectory()) return true;
});

const filePaths = [];
dirs.forEach((dir) => {
  const dirPath = path.join(rootDir, dir);
  const currFiles = fs.readdirSync(dirPath);
  currFiles.forEach((file) => {
    if (!ignoredFiles.has(file) && allowedExts.has(path.extname(file))) {
      filePaths.push(path.join(dirPath, file));
    }
  });
});

let content = "";
filePaths.forEach((filePath) => {
  const lines = fs.readFileSync(filePath).toString().split('\n');
  const currText = HTML.getFormattedText(filePath, lines);
  content += currText + '\n\n';
});

content =
  HTML.preConfigFile() +
  HTML.buildSummary() +
  content +
  HTML.postConfigFile();

fs.writeFileSync(buildFile, content);