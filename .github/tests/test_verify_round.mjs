// Run with @actions/expressions installed, or set ACTIONS_EXPRESSIONS_MODULE
// to the file URL of its dist/index.js. No GitHub access is needed by this test.
import assert from 'node:assert/strict';
import fs from 'node:fs';
const {Lexer, Parser, Evaluator, data} = await import(
  process.env.ACTIONS_EXPRESSIONS_MODULE || '@actions/expressions');
const workflow = fs.readFileSync(new URL('../workflows/verify.yml', import.meta.url), 'utf8');
const caller = workflow.split('  verify_all:\n')[1].split('\n  finalize:')[0];
const expression = caller.match(/^      round: \$\{\{ (.+) \}\}$/m)[1];
function evaluate(source, round) {
  const inputs = new data.Dictionary(...(round === undefined ? [] : [{
    key: 'round', value: typeof round === 'number'
      ? new data.NumberData(round) : new data.StringData(round),
  }]));
  const ast = new Parser(new Lexer(source).lex().tokens, ['inputs'], []).parse();
  return new Evaluator(ast, new data.Dictionary({key: 'inputs', value: inputs})).evaluate();
}
// Reproduce the dispatch-only defect: || supplies a numeric fallback for push,
// but preserves the type of a nonempty dispatch string (including '0').
assert.equal(evaluate('inputs.round || 0', undefined).kind, data.Kind.Number);
assert.equal(evaluate('inputs.round || 0', '1').kind, data.Kind.String);
let count = 0;
for (const round of [undefined, '', 0, '0', 1, '1', 2, '2', 3, '3']) {
  const result = evaluate(expression, round);
  assert.equal(result.kind, data.Kind.Number, `round=${JSON.stringify(round)}`);
  assert.equal(result.value, Number(round || 0));
  count++;
}
console.log(`round conversion: ${count} cases passed; original dispatch defect reproduced`);
