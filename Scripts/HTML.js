const path = require('path');
const Extract = require('./Extract');

const MAIN_STYLE = "styles.css";
const CODE_STYLE = "highlight/solarized-light.css";
const HIGHLIGHT =  "highlight/highlight.pack.js";

const TOC = {};

class HTML {
  static preConfigFile() {
    return (`
      <!DOCTYPE html>
      <html lang="en">
      <head>
        <meta charset="UTF-8">
        <title>Coding Interview Solutions - Felipe Thome</title>
        <link rel="stylesheet" href="${MAIN_STYLE}">
        <link rel="stylesheet" href="${CODE_STYLE}">
      </head>
      <body>
        <div class="container">
          <h1>Algorithm Problems</h1>
          <h3>Solutions by Felipe Thomé.</h3>
          <h3>The problems descriptions are from interviewbit.com.</h3>
    `);
  }

  static postConfigFile() {
    return (`
        </div>
        <script src="${HIGHLIGHT}"></script>
        <script>hljs.initHighlightingOnLoad();</script>
      </body>
      </html>
    `);
  }

  static buildSummary() {
    const keys = Object.keys(TOC);
    let links = "";

    for (let key of keys) {
      links += `<li><a href="#${key}">${TOC[key]}</a></li>`;
    }

    return (`
      <div class="summary-container">
        <h1>Summary</h1>
        <ul>
          ${links}
        </ul>
      </div>
    `);
  }

  static escape(text) {
    return text.replace(/</g, '&lt;').replace(/>/g, '&gt;');
  }

  static getFormattedTitle(filePath) {
    const currDirs = filePath.split(path.sep);
    const parentDir = currDirs[currDirs.length - 2];

    const title = parentDir.replace(/(^[a-z]|\-[a-z])/g, (match) => {
      return match.length == 1 ? match[0].toUpperCase() :
        ' ' + match[1].toUpperCase();
    });

    TOC[parentDir] = title;

    return (`
      <div>
        <h1 id="${parentDir}">
          ${title}
        </h1>
      </div>
    `);
  }

  static getFormattedComments(lines) {
    let text = '';
    const commentsRe = /^\s\*\s?/;

    for (let i = 0; i < lines.length; i++) {
      let curr = lines[i].replace(commentsRe, '') + '\n';
      curr = curr.replace('Time complexity:', '<b>Time complexity:</b>');
      curr = curr.replace('Space complexity:', '<b>Space complexity:</b>');
      curr = curr.replace('Example:', '<b>Example:</b>');
      curr = curr.replace('Explanation:', '<b>Explanation:</b>');
      text += curr;
    }

    return (`
      <div> 
        <pre class="custom-comments">
          ${text}
        </pre>
      </div>
    `);
  }

  static getFormattedCode(lines) {
    return (`
      <div><pre><code class="cpp custom-code">
        ${HTML.escape(lines.join('\n'))}
      </code></pre></div>
    `);
  }

  static getFormattedText(filePath, lines) {
    const filteredLines = Extract.getUsefulText(lines);
    const pieces = Extract.getTextPieces(filteredLines);

    Extract.removeLineBreaks(pieces.code);

    const titleText = HTML.getFormattedTitle(filePath);
    const commentsText = HTML.getFormattedComments(pieces.comments);
    const codeText = HTML.getFormattedCode(pieces.code);

    return titleText + commentsText + codeText + '<hr>';
  }
}

module.exports = HTML;