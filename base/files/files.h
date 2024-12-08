//
// Created by daicanglan on 2024/12/8.
//

#ifndef FILES_H
#define FILES_H
#include <cstdint>


namespace base {
class File {
public:
    enum Flags: uint32_t {
        FLAG_OPEN = 1 << 0,            // Opens a file, only if it exists.
        FLAG_CREATE = 1 << 1,          // Creates a new file, only if it does not
                                       // already exist.
        FLAG_OPEN_ALWAYS = 1 << 2,     // May create a new file.
        FLAG_CREATE_ALWAYS = 1 << 3,   // May overwrite an old file.
        FLAG_OPEN_TRUNCATED = 1 << 4,  // Opens a file and truncates it, only if it
                                       // exists.
        FLAG_READ = 1 << 5,
        FLAG_WRITE = 1 << 6,
        FLAG_APPEND = 1 << 7,
        FLAG_WIN_EXCLUSIVE_READ = 1 << 8,   // Windows only. Opposite of SHARE.
        FLAG_WIN_EXCLUSIVE_WRITE = 1 << 9,  // Windows only. Opposite of SHARE.
        FLAG_ASYNC = 1 << 10,
        FLAG_WIN_TEMPORARY = 1 << 11,  // Windows only.
        FLAG_WIN_HIDDEN = 1 << 12,     // Windows only.
        FLAG_DELETE_ON_CLOSE = 1 << 13,
        FLAG_WRITE_ATTRIBUTES = 1 << 14,  // File opened in a mode allowing writing
                                          // attributes, such as with SetTimes().
        FLAG_WIN_SHARE_DELETE = 1 << 15,  // Windows only.
        FLAG_TERMINAL_DEVICE = 1 << 16,   // Serial port flags.
        FLAG_WIN_BACKUP_SEMANTICS = 1 << 17,  // Windows only.
        FLAG_WIN_EXECUTE = 1 << 18,           // Windows only.
        FLAG_WIN_SEQUENTIAL_SCAN = 1 << 19,   // Windows only.
        FLAG_CAN_DELETE_ON_CLOSE = 1 << 20,  // Requests permission to delete a file
                                             // via DeleteOnClose() (Windows only).
                                             // See DeleteOnClose() for details.
        FLAG_WIN_NO_EXECUTE =
            1 << 21,  // Windows only. Marks the file with a deny ACE that prevents
                      // opening the file with EXECUTE access. Cannot be used with
                      // FILE_WIN_EXECUTE flag. See also PreventExecuteMapping.
    };

    struct Info {
        Info();
        ~Info();

        int64_t size = 0; // byte
        bool is_directory = false;
        bool is_symbolic_link = false;

        Time last_modified;
        Time last_accessed;
        Time creation_time;


    };
};
}




#endif //FILES_H
