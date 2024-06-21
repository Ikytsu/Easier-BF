# Syntax Infos

## Vanilla BF Syntax

- `+`: Increment the current cell by one.
- `-`: Decrement the current cell by one.
- `>`: Move the pointer to the next cell.
- `<`: Move the pointer to the previous cell.
- `.`: Output the ASCII or integer value depending on `$`, which is explained in the Easier-BF Addons section.

## Easier-BF Addons

- `$`: Switch between ASCII and integer value output for `.`. Default is ASCII.
- `#`: Assign the next character's ASCII value to the current pointer.
- `\`: Create a pointer table inside the current pointer with one element. Reusing `\\` increments the table size by one, allowing for nested tables.
- `*`: Enter the child pointer table.
- `&`: Enter the parent pointer table.
- `/`: Delete the pointer table inside the current pointer and all its children.
- `%`: Delete one element from the pointer table inside the current pointer.

## Editable

You can customize the syntax and properties. For example, `\` can be modified to add two elements instead of one. Everything is editable.
