//
//  DAONVoiceQuality.h
//
//  Copyright (c) 2015 Daon. All rights reserved.
//


// Audio Quality
// - Keys to build a dictionary for an audio quality check
static const NSString * kDaonVoiceMaxLoudnessThreshold              = @"daon.voice.max.loudness.threshold";
static const NSString * kDaonVoiceMinVoiceActivityLevelThreshold    = @"daon.voice.min.voice.activity.level.threshold";
static const NSString * kDaonVoiceMinDurationThreshold              = @"daon.voice.min.duration.threshold";
static const NSString * kDaonVoiceMinSignalLevelThreshold           = @"daon.voice.min.signal.level.threshold";
static const NSString * kDaonVoiceMinTextValidationScoreThreshold   = @"daon.voice.min.tv.score.threshold";
static const NSString * kDaonVoiceMaxTextValidationAlignThreshold   = @"daon.voice.max.tv.align.threshold";

// - Keys returned from audioQuality
static const NSString * kDaonVoiceResultCode                        = @"quality.result.code";
static const NSString * kDaonVoiceResultLoudness                    = @"quality.result.loudness";
static const NSString * kDaonVoiceResultLoudnessMax                 = @"quality.result.loudness.max";
static const NSString * kDaonVoiceResultVoiceActivityLevel          = @"quality.result.voice.activity.level";
static const NSString * kDaonVoiceResultVoiceActivityLevelMin       = @"quality.result.voice.activity.level.min";
static const NSString * kDaonVoiceResultDuration                    = @"quality.result.duration";
static const NSString * kDaonVoiceResultDurationMin                 = @"quality.result.duration.min";
static const NSString * kDaonVoiceResultSignalLevel                 = @"quality.result.signal.level";
static const NSString * kDaonVoiceResultSignalLevelMin              = @"quality.result.signal.level.min";
static const NSString * kDaonVoiceResultTextValidationScore         = @"quality.result.tv.score";
static const NSString * kDaonVoiceResultTextValidationScoreMin      = @"quality.result.tv.score.min";
static const NSString * kDaonVoiceResultTextValidationAlignScore    = @"quality.result.tv.align.score";
static const NSString * kDaonVoiceResultTextValidationAlignScoreMax = @"quality.result.tv.align.score.max";

static const NSString * kDaonVoiceResultSpeechActivityScoreRatio    = @"quality.result.speech.activity.score.ratio";
static const NSString * kDaonVoiceResultRecordingQualityScoreRatio  = @"quality.result.score.recording.quality";
static const NSString * kDaonVoiceResultTextValidationScoreRatio    = @"quality.result.tv.score.ratio";

static const int        kDaonVoiceResultPass                   = 0;
static const int        kDaonVoiceFailedTooSoft                = 1;
static const int        kDaonVoiceFailedTooNoisy               = 2;
static const int        kDaonVoiceFailedTooSoftSpeechClarity   = 3;
static const int        kDaonVoiceFailedUtteranceTooShort      = 4;
static const int        kDaonVoiceFailedTooLoud                = 5;
static const int        kDaonVoiceFailedFileIsCorrupted        = 6;
static const int        kDaonVoiceFailedFileIsEmpty            = 7;
static const int        kDaonVoiceFailedWrongUtteranceDetected = 8;
static const int        kDaonVoiceFailedUnsupportedFormat      = 9;

static const int        kDaonVoiceFailedBackgroundModelMismatch =  101;
static const int        kDaonVoiceFailedUnknownUtteranceModel    = 103;
static const int        kDaonVoiceFailedUnknownNonUtteranceModel = 104;

static const int        kDaonVoiceErrorIncorrectParameters    = 1000;
static const int        kDaonVoiceErrorExceptionOccurred      = 1001;
static const int        kDaonVoiceErrorNotInitialized         = 1002;



@protocol DAONVoiceQuality <NSObject>

- (id) initWithBundle:(NSBundle *)bundle modelDirectory:(NSString *)dir;

// TextValidation Text Phrase
- (NSString *) phraseTextWithError:(NSError **) errorPtr;

// Voice quality
- (void) validateAudioQuality:(NSData *) audioData completionHandler:(void (^)(NSDictionary* ,NSError*))handler;

// Quality setters
- (void) setQuality:(BOOL) testQuality;
- (void) setTextValidation:(BOOL) textValidation;
- (void) setCustomQualityParams:(NSDictionary*) customParams;

// Language/PhraseId
- (void) setLanguage:(NSString *) language;
- (void) setPhraseId:(NSString *) phraseId;
- (void) setFrequency:(unsigned int) frequency;

@end

@interface DAONVoiceQuality : NSObject<DAONVoiceQuality>
@end
