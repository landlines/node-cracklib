node-cracklib - C++ binding to cracklib for checking password strength.

### System Compatibility

`node-cracklib` is only compatible with linux and BSD-like systems.
It has been tested on

- Debian
- CentOS
- netbsd

### Node Compatibility

`node-cracklib` is tested with the following node versions:
- 12.x
- 14.x
- 15.x
- 16.x
- 17.x
- 18.x
- 19.x
- 20.x

### Installing 

Note that this package requires that the cracklib development libraries are installed. 
Installation may vary on your system but, for example on Debian:
    
    $ apt-get install libcrack2-dev

To install via npm:
    
    $ npm install cracklib

Or clone the repository and build from source:

    $ git clone git@github.com:danielsen/node-cracklib.git
    $ node-gyp configure -- -DMODULE_NAME=cracklib -DBUILD_TARGET=/path/to/app
    $ node-gyp build

### Usage

`node-cracklib` exposes both `fascistCheck` and `fascistCheckUser` from the
`cracklib` library using the following methods:

- `fascistCheck(password[, dictionaryPath])`
- `fascistCheckAsync(password[, dictionaryPath], callback)`
- `fascistCheckUser(password, user, gecos[, dictionaryPath])`
- `fascistCheckUserAsync(password, user, gecos[, dictionaryPath], callback)`

`fascistCheck()` uses the currently logged in user when checking passwords. 
`fascistCheckUser()` allows submission of an arbitray user and user gecos
field. The submitted user need not be a valid user on your system. A phony
username and gecos can be used as can `null` or an empty string value. Both
`user` and `gecos` are required parameters when using `fascistCheckUser()`
or the async variant.

Both methods and their async variants support custom dictionaries using the
optional `dictionaryPath` parameter. The default dictionary is used otherwise.

### Response

The response to all methods is a simple dictionary response with a single 
member, `message`. `message` is a `String` if the password is considered weak 
and `null` if the password is considered good. The messages are passed directly
from the `cracklib` C library and are not changed in any way by this module.

    {
      "message": String | null - Return value from the password check
    }

### Examples

    let cracklib = require('cracklib');

    // fascistCheck()
    let reponse = cracklib.fascistCheck('somePassword');

    // fascistCheck() with a custom dictionary
    let response = cracklib.fascistCheck('somePassword', '/path/to/dictionary');

    // fascistCheckAsync()
    cracklib.fascistCheckAsync('somePassword', (r) => {
        console.log(r.message);
    });

    // fascistCheckAsync() with a custom dictionary
    cracklib.fascistCheckAsync('somePassword', '/path/to/dictionary', (r) => {
        console.log(r.message);
    });

    // fascistCheckUser()
    let response = cracklib.fascistCheckUser('somePassword', 'alice', null);

    // fascistCheckUser() with a custom dictionary
    let response = cracklib.fascistCheckUser('somePassword', 'alice', null,
        '/path/to/dictionary');

    // fascistCheckUserAsync()
    cracklib.fascistCheckUserAsync('somePassword', 'alice', null, (r) => {
        console.log(r.message);
    });

    // fascistCheckUserAsync() with a custom dictionary
    cracklib.fascistCheckUserAsync('somePassword', 'alice', null, 
        '/path/to/dictionary', (r) => {
            console.log(r.message);
        });


### Support

Please file bugs, issues, etc. at https://github.com/landlines/node-cracklib/issues. PRs for bug fixes are welcome.

### Development

If you want to hack on this code you'll need to make sure that the following are installed on your system:

- NodeJs development libraries
- Cracklib development libraries
- node-gyp

### Clone and Build

    $ git clone git@github.com:landlines/node-cracklib.git
    $ node-gyp configure -- -DMODULE_NAME=cracklib -DBUILD_TARGET=/path/to/app
    $ node-gyp build

### References

- [cracklib library source](https://github.com/cracklib/cracklib)
