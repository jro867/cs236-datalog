#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/DatalogProgram.o \
	${OBJECTDIR}/Expression.o \
	${OBJECTDIR}/Fact.o \
	${OBJECTDIR}/FactList.o \
	${OBJECTDIR}/HeadPredicate.o \
	${OBJECTDIR}/IdList.o \
	${OBJECTDIR}/Input.o \
	${OBJECTDIR}/Lex.o \
	${OBJECTDIR}/Node.o \
	${OBJECTDIR}/Operator.o \
	${OBJECTDIR}/Parameter.o \
	${OBJECTDIR}/ParameterList.o \
	${OBJECTDIR}/ParsingException.o \
	${OBJECTDIR}/Predicate.o \
	${OBJECTDIR}/PredicateList.o \
	${OBJECTDIR}/Query.o \
	${OBJECTDIR}/QueryList.o \
	${OBJECTDIR}/Rule.o \
	${OBJECTDIR}/RuleList.o \
	${OBJECTDIR}/Scheme.o \
	${OBJECTDIR}/SchemesList.o \
	${OBJECTDIR}/State.o \
	${OBJECTDIR}/StringList.o \
	${OBJECTDIR}/Token.o \
	${OBJECTDIR}/TokenType.o \
	${OBJECTDIR}/TokensReader.o \
	${OBJECTDIR}/Utils.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lexer

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lexer: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lexer ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/DatalogProgram.o: DatalogProgram.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/DatalogProgram.o DatalogProgram.cpp

${OBJECTDIR}/Expression.o: Expression.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Expression.o Expression.cpp

${OBJECTDIR}/Fact.o: Fact.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Fact.o Fact.cpp

${OBJECTDIR}/FactList.o: FactList.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/FactList.o FactList.cpp

${OBJECTDIR}/HeadPredicate.o: HeadPredicate.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/HeadPredicate.o HeadPredicate.cpp

${OBJECTDIR}/IdList.o: IdList.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/IdList.o IdList.cpp

${OBJECTDIR}/Input.o: Input.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Input.o Input.cpp

${OBJECTDIR}/Lex.o: Lex.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Lex.o Lex.cpp

${OBJECTDIR}/Node.o: Node.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Node.o Node.cpp

${OBJECTDIR}/Operator.o: Operator.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Operator.o Operator.cpp

${OBJECTDIR}/Parameter.o: Parameter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Parameter.o Parameter.cpp

${OBJECTDIR}/ParameterList.o: ParameterList.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/ParameterList.o ParameterList.cpp

${OBJECTDIR}/ParsingException.o: ParsingException.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/ParsingException.o ParsingException.cpp

${OBJECTDIR}/Predicate.o: Predicate.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Predicate.o Predicate.cpp

${OBJECTDIR}/PredicateList.o: PredicateList.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/PredicateList.o PredicateList.cpp

${OBJECTDIR}/Query.o: Query.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Query.o Query.cpp

${OBJECTDIR}/QueryList.o: QueryList.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/QueryList.o QueryList.cpp

${OBJECTDIR}/Rule.o: Rule.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Rule.o Rule.cpp

${OBJECTDIR}/RuleList.o: RuleList.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/RuleList.o RuleList.cpp

${OBJECTDIR}/Scheme.o: Scheme.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Scheme.o Scheme.cpp

${OBJECTDIR}/SchemesList.o: SchemesList.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/SchemesList.o SchemesList.cpp

${OBJECTDIR}/State.o: State.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/State.o State.cpp

${OBJECTDIR}/StringList.o: StringList.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/StringList.o StringList.cpp

${OBJECTDIR}/Token.o: Token.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Token.o Token.cpp

${OBJECTDIR}/TokenType.o: TokenType.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/TokenType.o TokenType.cpp

${OBJECTDIR}/TokensReader.o: TokensReader.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/TokensReader.o TokensReader.cpp

${OBJECTDIR}/Utils.o: Utils.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Utils.o Utils.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lexer

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
