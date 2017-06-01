.name "my name"
.comment "my comment"

live %4294967295
ld %2, r2
st r2, 20
live %1
ld %0, r2
st r2, 20
live %1
lfork %12
lfork %12
live %4294967295
zjmp %4294967246
