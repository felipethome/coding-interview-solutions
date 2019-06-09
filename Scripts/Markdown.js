const path = require('path');
const Extract = require('./Extract');

const styles = '<style> p { white-space: normal; font-family: monospace; ' +
  'font-size: 10pt; }</style>\n';

class Markdown {
  static getFormattedTitle(filePath) {
    const currDirs = filePath.split(path.sep);
    const parentDir = currDirs[currDirs.length - 2];

    const title = parentDir.replace(/(^[a-z]|\-[a-z])/g, (match) => {
      return match.length == 1 ? match[0].toUpperCase() :
        ' ' + match[1].toUpperCase();
    });

    return title;
  }

  static getFormattedComments(lines) {
    let text = '';
    const commentsRe = /^\s\*\s?/;
    const spaceRe = / /g;

    for (let i = 0; i < lines.length; i++) {
      let currLine = lines[i].replace(commentsRe, '') + '\n';
      currLine = currLine.replace(spaceRe, '&nbsp;');
      text += currLine;
    }

    return text;
  }

  static getFormattedCode(lines) {
    return '```c++' + lines.join('\n') + '```';
  }

  static getFormattedText(lines) {
    const filteredLines = Extract.getUsefulText(lines);
    const pieces = Extract.getTextPieces(filteredLines);

    Extract.removeLineBreaks(pieces.code);

    const commentsText = Markdown.getFormattedComments(pieces.comments);
    const codeText = Markdown.getFormattedCode(pieces.code);

    return commentsText + '\n\n' + codeText;
  }
}

module.exports = Markdown;