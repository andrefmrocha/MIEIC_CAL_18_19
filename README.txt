CAL Project README:

- Libraries and API's:
    + GraphViewer API - provided in classes.
    + curlpp and curl - used on script to get bus lines information from official servers (directory stcp_scripts, file stcp_routes.cpp).
    + jsoncpp - used to read the server's response (json_reader.cpp).

Credits to Bernardo Santos (up201706534@fe.up.pt) for helping with codes_to_id.cpp.

- Compilation instructions:
    + To compile the project you need cmake.
    + Run $cmake . && make and execute with $./TripMate

- Input files:
    + All of our input files are in T11 directory.
    + Since only Porto has information about bus and subway lines, all of our examples run on T11/Porto files.
    + Background image from Porto (T11/Porto/map.png) download from OpenStreetMaps.
