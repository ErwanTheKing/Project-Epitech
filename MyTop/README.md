# 💼 libmy – Personal C Utility Library

<span style="color:#4CAF50;">`libmy` is a reusable toolbox of C helpers (strings, printing, math, memory, lists, etc.) wrapped in a ready-to-plug build system. Drop it into new projects, link the static archive, and skip rewriting the same utilities every time.</span>

## 🌟 Why libmy?
- <span style="color:#FFB703;">Centralizes the helpers you keep rewriting.</span>
- <span style="color:#8ECAE6;">Ships with styled Makefiles and a bootstrap script.</span>
- <span style="color:#CDA3FF;">Includes headers, tests, and guidelines so you can share it across projects.</span>

## 🗺️ Library map

| Module | Path | Purpose |
| --- | --- | --- |
| Strings | [`lib/my/manage_str`](lib/my/manage_str) | Length/copy helpers, case transforms, word arrays. |
| Operations | [`lib/my/opperations`](lib/my/opperations) | Numeric helpers, comparisons, sorting, swaps. |
| Printing | [`lib/my/printing`](lib/my/printing) | `my_printf`, printers for strings, numbers, bases. |
| `printf` flags | [`lib/my/printf_flags`](lib/my/printf_flags) | Internal flag parsing & specifier handlers. |
| Memory helpers | [`lib/my/malloc`](lib/my/malloc) | `my_strdup`, file-size helpers, safe open wrappers. |
| Linked lists | [`lib/my/linked_lists`](lib/my/linked_lists) | Generic list primitives: init, push/pop, search, sort. |
| Formatting structs | [`lib/my/strcture_management`](lib/my/strcture_management) | Structures used by formatted output. |
| Headers | [`lib/my/headers`](lib/my/headers) | Public headers mirrored into your `include/` folder. |

> <span style="color:#00AEEF;">Heads up:</span> Root-level sources (e.g., `main.c`) typically consume the library.

## 🛠️ Building

Use the styled root `Makefile`; it delegates to `lib/my/Makefile`.

### 🔄 Everything (library + main project)
```sh
make
```
- Builds `lib/my/libmy.a`.
- Builds the root executable defined in `Makefile`.

### 🧱 Library only
```sh
make -C lib/my
# or
(cd lib/my && make)
```
Produces the static archive `libmy.a` inside `lib/`.

## 🔗 Using libmy elsewhere

1. Copy or submodule the `lib/my` folder into your project.
2. Mirror the public headers (e.g., symlink `lib/my/headers` to your `include/`).
3. Include them in sources:
   ```c
   #include "include/my.h"
   ```
4. Link the archive when compiling:
   ```sh
   gcc -o my_program main.c -L./lib -lmy -I./include
   ```
5. (Optional) Add `make -C lib/my` to your project build before linking so the library stays up to date.

### 🧩 Sample Makefile snippet
```make
LIBDIR   = lib
LIBMYDIR = $(LIBDIR)/my
LIBMY    = -L$(LIBDIR) -lmy
CFLAGS  += -I./include

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBMYDIR)
	$(CC) -o $@ $(OBJ) $(LIBMY)
```
Assumes the headers from `lib/my/headers` are exposed through your `include/` path.

## 🧪 Tests & coverage

From the repo root:
```sh
make tests_run
```
Runs the unit tests in `tests/`. For coverage (if configured):
```sh
make coverage
```
Generates coverage instrumentation and reports (e.g., via `gcovr`). Test and coverage outputs are git-ignored.

## ⚙️ Tooling highlights

### 📝 Commit policy
`COMMIT_POLICY.md` documents lightweight rules plus symbolic prefixes:
- `{+}` add code or files
- `{-}` remove code or files
- `{~}` refactor/cleanup
- `{#}` bug fix
- `{!}` urgent/breaking change
- `{...}` docs-only
- `{%}` tests-only
Use them in commit titles (e.g., `{+} add: malloc helper`) and remember to pull/test before pushing.

### 🚧 Bootstrap new projects
`new_project.sh` clones this template and rewires metadata:
```sh
./new_project.sh <git-url> <target-folder> <project-name> <binary-name>
```
- Clones into `<target-folder>`
- Updates the root `Makefile` with the provided names
- Extends `.gitignore` for the chosen binary

## 🧱 Project structure

```
.
├── main.c
├── lib/
│   └── my/
│       ├── headers/
│       ├── linked_lists/
│       ├── manage_str/
│       ├── malloc/
│       ├── opperations/
│       ├── printing/
│       ├── printf_flags/
│       └── strcture_management/
├── tests/
│   ├── testin_hello_file
│   ├── testing_empty_file
│   └── unit_tests_lib.c
├── COMMIT_POLICY.md
├── Makefile
└── new_project.sh
```

## 🚀 Keep evolving the toolbox
- Add generic helpers as you encounter new needs.
- Harden existing functions with tests in `tests/`.
- Polish the Makefiles/tooling when your workflow evolves.

### 💬 Questions or ideas?
<span style="color:#E63946;">Open a GitHub Issue with suggestions, bug reports, or feature wishes—this library grows best with community feedback.</span>

Treat `libmy` as your default C helper kit—clone it, wire it in, and get straight to the problem you actually need to solve.
