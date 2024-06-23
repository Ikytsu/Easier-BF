# Configuration File Guidelines

To create a configuration file, name it `config.txt` and place it in the same directory where you launch the compiler (config.txt is different for each folder where you launch the compiler).

Separate each configuration declaration by a new line.

If no configuration file is found, the compiler will create an empty one with default settings.

## Configuration Options

### Syntax Configurations

- `add`: default is `+`
- `substract`: default is `-`
- `move_next`: default is `>`
- `move_previous`: default is `<`
- `output`: default is `.`
- `input`: default is `,`
- `output_type_switcher`: default is `$`
- `assign_char`: default is `#`
- `table_create`: default is `\`
- `table_gochild`: default is `*`
- `table_goparent`: default is `&`
- `table_delete`: default is `/`
- `table_remove`: default is `%`

### Value Configurations

- `add_subtract_value`: default is `1`
- `move_value`: default is `1`
- `output_type_switcher_default`: default is `ASCII`, other value: `INT`
- `table_create_value`: default is `1`
- `table_remove_value`: default is `1`

## Notes

- Any order of the configurations should work.
- If a configuration option is not specified, it will use the default value.
- Be cautious while editing the configuration file as some configurations depend on others. Improper settings can lead to memory leaks and other issues.
