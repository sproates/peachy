#include "expressionsource.h"

#include "expression.h"
#include "expressionfactory.h"
#include "log.h"
#include "tokensource.h"

namespace peachy {

  ExpressionSource::ExpressionSource(Log * logger,
    ExpressionFactory * expressionFactory, TokenSource * tokenSource) {
    this->logger = logger;
    this->expressionFactory = expressionFactory;
    this->tokenSource = tokenSource;
  }

  ExpressionSource::~ExpressionSource() {}
}
