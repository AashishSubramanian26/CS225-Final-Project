add_test( [==[Shortest Path]==] /workspaces/CS225-Final-Project/build/test [==[Shortest Path]==]  )
set_tests_properties( [==[Shortest Path]==] PROPERTIES WORKING_DIRECTORY /workspaces/CS225-Final-Project/build)
add_test( [==[Yen's Algo 1]==] /workspaces/CS225-Final-Project/build/test [==[Yen's Algo 1]==]  )
set_tests_properties( [==[Yen's Algo 1]==] PROPERTIES WORKING_DIRECTORY /workspaces/CS225-Final-Project/build)
add_test( [==[Yen's Algo one path]==] /workspaces/CS225-Final-Project/build/test [==[Yen's Algo one path]==]  )
set_tests_properties( [==[Yen's Algo one path]==] PROPERTIES WORKING_DIRECTORY /workspaces/CS225-Final-Project/build)
set( test_TESTS [==[Shortest Path]==] [==[Yen's Algo 1]==] [==[Yen's Algo one path]==])