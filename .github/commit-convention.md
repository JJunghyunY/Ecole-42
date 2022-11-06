Semantic Commit Messages
---

## Format

`[<TYPE>] (<scope>): <subject>`

`<body>`

`<footer(s)>`

`<scope>`, `<body>`, `<footer(s)>` is optional

---

## Example

```
[FEAT]: add commit convention.md
^----^  ^----------------------^
|     |
|     +-> Summary in present tense.
|
+-------> TYPE: FEAT, FIX, DOCS, STYLE, REFACTOR, TEST, CHORE
```

Commit Type:
- `FEAT`: (new feature for the user, not a new feature for build script)
- `FIX`: (bug fix for the user, not a fix to a build script)
- `DOCS`: (changes to the documentation)
- `STYLE`: (formatting, missing semi colons, etc; no production code change)
- `REFACTOR`: (refactoring production code, eg. renaming a variable)
- `TEST`: (adding missing tests, refactoring tests; no production code change)
- `CHORE`: (updating grunt tasks etc; no production code change)

Commit Subject Rules
- Separate subject from body with a blank line
- Limit the subject line to 50 characters
- Capitalize the subject line
- Do not end the subject line with a period

Commit Body Rules
- Use the imperative mood in the subject line
- Wrap the body at 72 characters
- Use the body to explain what and why vs. how

Commit Footer Rules
- The footer is optional and is used to reference issue tracker IDs.
- The Message Footer should contain any information about **Notes** and also Message Footer should be **recommended** [GitHub Issue](https://github.com/features#issues) ID Reference, Ex. `Issue #27`, `Fixes #1`, `Closes #2`, `Resolves #3`.

| Available keywords |
| ---------------------------------------- |
| Close, Closes, Closed, Closing, close, closes, closed, closing |
| Fix, Fixes, Fixed, Fixing, fix, fixes, fixed, fixing |
| Resolve, Resolves, Resolved, Resolving, resolve, resolves, resolved, resolving |
| Implement, Implements, Implemented, Implementing, implement, implements, implemented, implementing |

ex)
Resolves: #123
Ref: #456
Related to: #78, #9

**Notes** should start with the word `NOTE:` with a space or two newlines. The rest of the commit message is then used for this.
Available keywords:

---

## Complete Commit Format

```

Feat: add commit convention.md

add commit convention document

Resolves: #123
Ref: #456
Related to: #78, #9
```
---


References:
- https://www.conventionalcommits.org/
- https://udacity.github.io/git-styleguide/
- https://cbea.ms/git-commit/
- https://github.com/carloscuesta/gitmoji
- http://karma-runner.github.io/1.0/dev/git-commit-msg.html
- https://docs.github.com/en/issues/tracking-your-work-with-issues/linking-a-pull-request-to-an-issue
- https://docs.gitlab.com/ee/user/project/issues/managing_issues.html

