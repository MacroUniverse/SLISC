--- SLISC SQLite data file for variables -----
--- similar to Matlab's mat file ---

CREATE TABLE VARS (
	ID INT PRIMARY KEY AUTOINCREMENT, -- never change once created
	NAME TEXT UNIQUE NOT NULL, -- can be renamed
	TYPE_NUM INT NOT NULL, -- reference TYPES table
	SHAPE TEXT, -- e.g.  '10 20 30', NULL for scalar
	DATA BLOB, -- actual data, if NULL, then data is stored in another table named 'ID'
	FINISHED INT, -- has all data finished writing?
	FOREIGN KEY (TYPE_NUM) REFERENCES TYPES (TYPE_NUM)
);

CREATE TABLE TYPES (
	TYPE_NUM INT PRIMARY KEY, -- type number
	TYPE TEXT UNIQUE -- UCHAR, CHAR, UINT8, INT8, INT64 ... , SINGLE, DOUBLE ...
);

INSERT INTO TYPES VALUES (0,  'Bool');
INSERT INTO TYPES VALUES (1,  'Char');
INSERT INTO TYPES VALUES (2,  'Int');
INSERT INTO TYPES VALUES (3,  'Llong');
INSERT INTO TYPES VALUES (11, 'Uchar');
INSERT INTO TYPES VALUES (12, 'Uint');
INSERT INTO TYPES VALUES (13, 'Ullong');
INSERT INTO TYPES VALUES (20, 'Float');
INSERT INTO TYPES VALUES (21, 'Doub');
INSERT INTO TYPES VALUES (22, 'Ldoub');
INSERT INTO TYPES VALUES (23, 'Qdoub');
INSERT INTO TYPES VALUES (40, 'Fcomp');
INSERT INTO TYPES VALUES (41, 'Comp');
INSERT INTO TYPES VALUES (42, 'Lcomp');
INSERT INTO TYPES VALUES (43, 'Qcomp');
INSERT INTO TYPES VALUES (60, 'Fimag');
INSERT INTO TYPES VALUES (61, 'Imag');
INSERT INTO TYPES VALUES (62, 'Limag');
INSERT INTO TYPES VALUES (63, 'Qimag');

----- Example Data -----

INSERT INTO VARS (NAME, TYPE_NUM, SHAPE, DATA, FINISHED) VALUES ('myInt32', 2, NULL, 'w82h', 0);
UPDATE VARS SET FINISHED = 1 WHERE NAME = 'myInt32';

INSERT INTO VARS (NAME, TYPE_NUM, SHAPE, DATA, FINISHED) VALUES ('myBool', 0, NULL, 'a', 0);
UPDATE VARS SET FINISHED = 1 WHERE NAME = 'myBool';

INSERT INTO VARS (NAME, TYPE_NUM, SHAPE, DATA, FINISHED) VALUES ('myDoub', 0, '2 4 3', 'a2d4q6f8e0w4r2h4k1h21q24', 0);
UPDATE VARS SET FINISHED = 1 WHERE NAME = 'myDoub';

INSERT INTO VARS (NAME, TYPE_NUM, SHAPE, DATA, FINISHED) VALUES ('myHuge', 0, '3 5 6 9 10 100', NULL, 0);
CREATE TABLE '4' ( -- extra table for 'myHuge'
	BLOCK_ID INT PRIMARY KEY AUTOINCREMENT,
	BLOCK BLOB
);
INSERT INTO '4' (BLOCK) VALUES ('1234567890');
INSERT INTO '4' (BLOCK) VALUES ('1234567890');
INSERT INTO '4' (BLOCK) VALUES ('1234567890');
INSERT INTO '4' (BLOCK) VALUES ('123');
UPDATE VARS SET FINISHED = 1 WHERE NAME = 'myHuge';

-- get size ---
-- SELECT LENGTH(BLOCK) FROM '4'
-- SELECT COUNT(*) FROM '4'
