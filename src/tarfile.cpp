#include <iostream>
#include <fstream>
#include <cstdlib>
#include "lindenb/io/tarball.h"

int main(int argc,char** argv)
    {
    /* open file for writing */
    std::fstream out("archive.tar",std::ios::out);
    if(!out.is_open())
        {
        std::cerr << "Cannot open out" << std::endl;
        return EXIT_FAILURE;
        }
    /* create the tar file */
    lindenb::io::Tar tarball(out);
    /* add item 1 */
    tarball.put("myfiles/item1.txt","Hello World 1\n");
    /* add item 2 */
    tarball.put("myfiles/item2.txt","Hello World 2\n");
    /* add a file */
    tarball.putFile("tarfile.cpp","myfiles/code.cpp");
    /* finalize the tar file */
    tarball.finish();
    /* close the file */
    out.close();
    /* we're done */
    return EXIT_SUCCESS;;
    }
