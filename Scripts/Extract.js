class Extract {
  static removeLineBreaks(lines) {
    let i = lines.length - 1;

    while (i >= 0) {
      if (lines[i] === '') {
        let start = i;
        while (i >= 0 && lines[i] === '') i--;
        lines.splice(i + 1, start - i - 1);
      }
      i--;
    }
  }

  static getComments(lines) {
    let i = 0;
    const beginRe = /\/\*\*?/;
    const endRe = /\*\//;

    while (i < lines.length && !beginRe.test(lines[i])) i++;
    i++;

    if (i >= lines.length) return {start: 0, end: 0};

    let start = i;
    while (i < lines.length && !endRe.test(lines[i])) i++;
    let end = i;

    return {start: start, end: end};
  }

  static getUsefulText(lines) {
    const mainRe = /int\smain\s*\(.*\)\s*\{/;
    const includeRe = /#include\s.*/;
    const namespaceRe = /using\snamespace\s.*/;
    let i = 0;
    let filteredLines = [];

    while (i < lines.length && !mainRe.test(lines[i])) {
      if (includeRe.test(lines[i]) || namespaceRe.test(lines[i])) {
        i++;
        continue;
      }

      filteredLines.push(lines[i]);
      i++;
    }

    return filteredLines;
  }

  static getTextPieces(lines) {
    const indices = Extract.getComments(lines);
    const comments = indices.end ?
      lines.slice(indices.start, indices.end) : [];
    const code = indices.end ?
      lines.slice(indices.end + 1, lines.length) : lines.slice();

    return {comments: comments, code: code};
  }
}

module.exports = Extract;