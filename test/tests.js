var assert = require('assert');
var cracklib = require('../build/Release/cracklib');

const nonMatch = 'should have a null message for a non-matching password';
const match = 'should have a warning message for a matching password';
describe('cracklib', function () {
    describe('#fascistCheck()', function () {
        it(nonMatch, function () {
            assert.equal(cracklib.fascistCheck('Y0urPa55word').message, null);
        });
        it(match, function () {
            assert.equal(cracklib.fascistCheck('Pa55word').message, 
                'it is based on a dictionary word');
        });
    });

    describe('#fascistCheckAsync()', function () {
        it(nonMatch, function (done) {
            cracklib.fascistCheckAsync('Y0urPa55word', function (res) {
                assert.equal(null, res.message);
                done();
            });
        });
        it(match, function (done) {
            cracklib.fascistCheckAsync('Pa55word', function (res) {
                assert.equal('it is based on a dictionary word', res.message);
                done();
            });
        });
    });

    describe('#fascistCheckUser()', function () {
        it(nonMatch, function () {
            assert.equal(cracklib.fascistCheckUser('Y0urPa55word', 
                'alice', 'alice').message, null);
        });
        it(match, function () {
            assert.equal(cracklib.fascistCheckUser('Pa55word',
                'bob', 'bob').message, 'it is based on a dictionary word');
        });
    });

    describe('#fascistCheckUserAsync()', function () {
        it(nonMatch, function (done) {
            cracklib.fascistCheckUserAsync('Y0urPa55word', 'alice', null, 
                function (res) {
                    assert.equal(null, res.message);
                    done();
                });
        });
        it(match, function (done) {
            cracklib.fascistCheckUserAsync('Pa55word', 'alice', null,
                function (res) {
                    assert.equal('it is based on a dictionary word', 
                        res.message);
                    done();
                });
        });
    });
});
