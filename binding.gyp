{ 
  "targets": [
    {
      "target_name"   : "cracklib",
      "sources"       : [ 
                          "src/check.cc",
                          "src/functions.cc",
                          "src/cracklib.cc"
                        ],
      "include_dirs"  : [ "<!(node -e \"require('nan')\")" ],
      "libraries"     : [ "-lcrack" ],
      "cflags"        : [ "-Wparentheses", "-std=c++17" ]
    }
  ]
}
